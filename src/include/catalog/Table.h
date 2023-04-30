//
// Created by ame on 2023/4/30.
//

#ifndef PIGGYDB_TABLE_H
#define PIGGYDB_TABLE_H


#include <string>
#include <vector>
#include "Colum.h"

class Table {
public:
    Table(int tableId, const std::string &tableName, const std::vector<Colum> &col);
    bool InsertRow(const std::vector<Colum> &col){

    }
private:
    int table_id_;
    std::string table_name_;
    std::vector<Colum> col_;
};


#endif //PIGGYDB_TABLE_H
