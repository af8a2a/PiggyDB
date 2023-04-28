//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_BUFFERPOOL_H
#define PIGGYDB_BUFFERPOOL_H

#include <unordered_map>
#include "Page.h"
#include "DiskManager.h"
class BufferPool {

public:
    Page* FetchPage(int page_id);
    Page* UnpinPage(int page_id);
    Page* NewPage(int page_id);
private:
    int g_page_id_;
    DiskManager* diskManager_;
    size_t pool_size_;
    std::mutex latch_;
    std::unordered_map<int,Page*> hash;
};


#endif //PIGGYDB_BUFFERPOOL_H
