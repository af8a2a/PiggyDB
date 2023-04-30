//
// Created by ame on 2023/4/30.
//

#ifndef PIGGYDB_DATABASE_H
#define PIGGYDB_DATABASE_H


#include <string>
#include <unordered_map>
#include "Table.h"

class DataBase {
public:
    int AllocTableid(){
        return g_table_id++;
    }
private:
    int g_table_id=0;
    std::string name_;
    std::unordered_map<std::string,Table> table_name_;
    std::unordered_map<int,Table> table_id_;
};


#endif //PIGGYDB_DATABASE_H
