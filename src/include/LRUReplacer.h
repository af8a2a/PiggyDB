//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_LRUREPLACER_H
#define PIGGYDB_LRUREPLACER_H


#include <unordered_map>
#include <list>
#include "Replacer.h"

class LRUReplacer: public Replacer{
private:
    size_t capacity_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
public:
    bool Evict(int *page_id) override;

    void RecordAccess(int *page_id) override;

    void SetEvictable(int frame_id, bool set_evictable) override;

    void Remove(int frame_id) override;
};


#endif //PIGGYDB_LRUREPLACER_H
