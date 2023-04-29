//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_PAGE_H
#define PIGGYDB_PAGE_H

#include <mutex>
#include <cstring>

class Page {
private:

    std::mutex mtx_;
    int page_id_ = -1;
    int pin_count_ = 0;
    bool dirty = false;
    char data[4096]{};
public:
    Page() {
        memset(data, 0, sizeof(data));
    }

    void SetPageid(int page_id) {
        page_id_ = page_id;
    }

    int getPinCount() const {
        return pin_count_;
    }

    void setPinCount(int pinCount) {
        pin_count_ = pinCount;
    }

    bool isDirty() const {
        return dirty;
    }

    void setDirty(bool dirty) {
        Page::dirty = dirty;
    }

    void Pin(){
        pin_count_++;
    }
    void UnPin(){
        pin_count_--;
    }
    int GetPageid() {
        return page_id_;
    }

    bool IsDirty() {
        return dirty;
    }

    char *Data() {
        return data;
    }
    void Clear(){
        memset(data, 0, sizeof(data));
    }
};
#endif //PIGGYDB_PAGE_H
