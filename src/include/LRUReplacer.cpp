//
// Created by ame on 2023/4/28.
//

#include "LRUReplacer.h"

bool LRUReplacer::Evict(int *page_id) {
    return Replacer::Evict(page_id);
}

void LRUReplacer::RecordAccess(int *page_id) {
    Replacer::RecordAccess(page_id);
}

void LRUReplacer::SetEvictable(int frame_id, bool set_evictable) {
    Replacer::SetEvictable(frame_id, set_evictable);
}

void LRUReplacer::Remove(int frame_id) {
    Replacer::Remove(frame_id);
}
