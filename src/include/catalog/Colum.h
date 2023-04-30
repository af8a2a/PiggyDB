//
// Created by ame on 2023/4/30.
//

#ifndef PIGGYDB_COLUM_H
#define PIGGYDB_COLUM_H


#include <string>
#include "../def.h"

class Colum {
public:
    Colum(ColumType type, bool nullable, bool recordSize, const std::string &name, const std::string &data);

    ColumType getType() const {
        return type_;
    }

    void setType(ColumType type) {
        type_ = type;
    }

    bool isNullable() const {
        return nullable_;
    }

    void setNullable(bool nullable) {
        nullable_ = nullable;
    }

    bool isRecordSize() const {
        return record_size_;
    }

    void setRecordSize(bool recordSize) {
        record_size_ = recordSize;
    }

    const std::string &getName() const {
        return name_;
    }

    void setName(const std::string &name) {
        name_ = name;
    }

    const std::string &getData() const {
        return data_;
    }

    void setData(const std::string &data) {
        data_ = data;
    }

private:
    ColumType type_;
    bool nullable_;
    bool record_size_;
    std::string name_;
    std::string data_;

};


#endif //PIGGYDB_COLUM_H
