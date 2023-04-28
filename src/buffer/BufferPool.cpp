//
// Created by ame on 2023/4/28.
//

#include "../include/BufferPool.h"

Page *BufferPool::FetchPage(int page_id) {
    if(hash.contains(page_id)){
        hash[page_id]->Pin();
        return hash[page_id];
    }else{

    }
}

Page *BufferPool::UnpinPage(int page_id) {
    return nullptr;
}
