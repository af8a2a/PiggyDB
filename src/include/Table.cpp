//
// Created by ame on 2023/4/30.
//

#include "catalog/Table.h"

Table::Table(int tableId, const std::string &tableName, const std::vector<Colum> &col) : table_id_(tableId),
                                                                                         table_name_(tableName),
                                                                                         col_(col) {

}
