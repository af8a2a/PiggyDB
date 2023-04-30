//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_BUFFERPOOL_H
#define PIGGYDB_BUFFERPOOL_H

#include <unordered_map>
#include "storage/Page/Page.h"
#include "storage/DiskManager.h"
#include "LRUReplacer.h"

class BufferPool {

public:
    BufferPool(DiskManager *diskManager, size_t poolSize);

    virtual ~BufferPool();

    Page* FetchPage(page_id_t page_id);
    bool UnpinPage(page_id_t page_id,bool is_dirty);
    Page* NewPage(page_id_t* page_id);
    bool Flush(page_id_t page_id);
    bool DeletePage(page_id_t page_id);
private:
    std::atomic<int> g_page_id_=0;
    DiskManager* diskManager_;
    size_t pool_size_;
    std::mutex latch_;
    std::unordered_map<page_id_t,frame_id_t > page_table;
    std::list<frame_id_t> free_list_;
    Page* window_;
    LRUKReplacer* replacer_;
};


#endif //PIGGYDB_BUFFERPOOL_H
