//
// Created by ame on 2023/4/30.
//

#include "../include/catalog/Colum.h"

Colum::Colum(ColumType type, bool nullable, bool recordSize, const std::string &name, const std::string &data) : type_(
        type), nullable_(nullable), record_size_(recordSize), name_(name), data_(data) {

}
