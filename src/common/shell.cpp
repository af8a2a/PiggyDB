//
// Created by ame on 2023/4/30.
//

#include <regex>
#include "../include/common/shell.h"

void shell::read(std::string &SQL) {

}

std::string shell::SqlRewriter(std::string &SQL) {
    for(auto& i:SQL){
        i= toupper(i);
    }
    execute(SQL);

}

void shell::execute(std::string& SQL) {
    std::vector<std::string> command=Prase(SQL);
    if(command.empty()){
        throw std::runtime_error("SQL error");
    }
    Op op;
    if(command[0]=="SELECT"){
        op=Op::SELECT;
        //mock

    }
}

std::vector<std::string> shell::Prase(std::string& SQL) {
    std::vector<std::string> words;
    std::regex re("\\s+"); // 匹配一个或多个空白字符
    std::sregex_token_iterator it(SQL.begin(), SQL.end(), re, -1); // 分割字符串
    std::sregex_token_iterator end; // 结束迭代器
    while (it != end) // 遍历分割结果
    {
        words.push_back(*it);
        it++;
    }

    return words;
}
