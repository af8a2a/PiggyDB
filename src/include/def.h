//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_DEF_H
#define PIGGYDB_DEF_H
constexpr int PAGE_SIZE = 4096;
static constexpr int INVALID_PAGE_ID = -1;                                           // invalid page id
using page_id_t=int;
using frame_id_t=size_t;
enum class ColumType{
        BOOL,
        INT,
        CHAR,
        VARCHAR,
};
#endif //PIGGYDB_DEF_H
