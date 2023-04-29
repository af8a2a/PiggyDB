//
// Created by ame on 2023/4/28.
//

#include "../include/BufferPool.h"

BufferPool::BufferPool(DiskManager *diskManager, size_t poolSize) : diskManager_(diskManager), pool_size_(poolSize) {
    window_ = new Page[pool_size_];
    replacer_ = new LRUKReplacer(pool_size_, 2);
    for (size_t i = 0; i < pool_size_; ++i) {
        free_list_.emplace_back(static_cast<int>(i));
    }
}

Page *BufferPool::FetchPage(page_id_t page_id) {
    std::scoped_lock<std::mutex> lock(latch_);
    if (page_table.contains(page_id)) {
        frame_id_t frame = page_table[page_id];
        window_[frame].Pin();
        replacer_->RecordAccess(frame);
        replacer_->SetEvictable(frame, false);
        return &window_[frame];
    }
    frame_id_t frame = -1;
    for (int i = 0; i < pool_size_; i++) {
        if (window_[i].getPinCount() == 0) {
            frame = i;
            break;
        }
    }
    if (frame == -1) {
        return nullptr;
    }
    if (!free_list_.empty()) {
        frame = free_list_.front();
        free_list_.pop_front();
    } else {
        bool success = replacer_->Evict(&frame);
        if (success) {
            if (window_[frame].isDirty()) {
                diskManager_->WritePage(window_[frame].GetPageid(), window_[frame].Data());
                window_[frame].setDirty(false);
            }
            window_[frame].Clear();
            page_table.erase(window_[frame].GetPageid());
        }
    }
    page_table[page_id]=frame;
    window_[frame].Pin();
    window_[frame].setDirty(false);
    diskManager_->ReadPage(page_id,window_[frame].Data());
    replacer_->RecordAccess(frame);
    replacer_->SetEvictable(frame,false);
    return &window_[frame];
}

bool
BufferPool::UnpinPage(page_id_t page_id, bool is_dirty) {
    if (!page_table.contains(page_id)) {
        return false;
    }
    frame_id_t frameId = page_table[page_id];
    if (window_[frameId].getPinCount() <= 0) {
        return false;
    }
    if (is_dirty) {
        window_[frameId].setDirty(is_dirty);
    }
    window_[frameId].UnPin();
    if (window_[frameId].getPinCount() == 0) {
        replacer_->SetEvictable(frameId, true);
    }
    return true;
}

Page *BufferPool::NewPage(page_id_t *page_id) {
    std::scoped_lock<std::mutex> lock(latch_);
    frame_id_t frameId = 0;
    if (!free_list_.empty()) {
        frameId = free_list_.front();
        free_list_.pop_front();
    } else {
        bool success = replacer_->Evict(&frameId);
        if (success) {
            if (window_[frameId].IsDirty()) {
                diskManager_->WritePage(window_[frameId].GetPageid(), window_[frameId].Data());
                window_[frameId].setDirty(false);
            }
            page_table.erase(window_[frameId].GetPageid());

        } else {
            return nullptr;
        }

    }
    g_page_id_++;
    *page_id = g_page_id_;
    page_table[g_page_id_] = frameId;
    window_[frameId].Pin();
    window_[frameId].SetPageid(g_page_id_);
    replacer_->RecordAccess(frameId);
    replacer_->SetEvictable(frameId, false);
    return &window_[frameId];
}

bool BufferPool::Flush(page_id_t page_id) {
    if(page_id==INVALID_PAGE_ID){
        return false;
    }
    if(!page_table.contains(page_id)){
        return false;
    }
    diskManager_->WritePage(page_table[page_id],window_[page_table[page_id]].Data());
    return true;
}

bool BufferPool::DeletePage(page_id_t page_id) {
    std::scoped_lock<std::mutex> lock(latch_);
    if(page_id==INVALID_PAGE_ID){
        return false;
    }
    if(!page_table.contains(page_id)){
        return true;
    }
    frame_id_t frameId=page_table[page_id];
    if(window_[frameId].getPinCount()!=0){
        return false;
    }

    replacer_->Remove(frameId);
    window_[frameId].Clear();
    window_[frameId].SetPageid(INVALID_PAGE_ID);
    window_[frameId].setPinCount(0);
    window_[frameId].setDirty(false);
    page_table.erase(page_id);
    free_list_.push_back(frameId);
    return false;
}

BufferPool::~BufferPool() {
    delete[] window_;

}
