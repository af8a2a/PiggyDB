//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_REPLACER_H
#define PIGGYDB_REPLACER_H


#include "storage/Page/Page.h"

class Replacer {
public:
    virtual bool Evict(int* page_id);
    virtual void RecordAccess(int page_id);
    virtual void Remove(int frame_id);
    virtual void SetEvictable(int frame_id, bool evictable);

};


#endif //PIGGYDB_REPLACER_H
