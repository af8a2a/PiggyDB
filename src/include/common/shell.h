//
// Created by ame on 2023/4/30.
//

#ifndef PIGGYDB_SHELL_H
#define PIGGYDB_SHELL_H


#include <string>
#include <vector>

enum class Op{
    SELECT,
    INSERT
};
class shell {
public:
    void read(std::string& SQL);
private:
    std::vector<std::string> Prase(std::string& SQL);
    std::string SqlRewriter(std::string& SQL);
    void execute(std::string& SQL);
};


#endif //PIGGYDB_SHELL_H
