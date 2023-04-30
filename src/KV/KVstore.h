//
// Created by ame on 2023/4/30.
//

#ifndef PIGGYDB_KVSTORE_H
#define PIGGYDB_KVSTORE_H


#include <string>
#include <unordered_map>
#include <memory>
#include <optional>

class KVstore {
public:
    KVstore();

    virtual ~KVstore();

    void Del(const std::string& key);
    std::optional<std::string> Get(const std::string& key);
    void Put(const std::string& key,const std::string& val);
private:
    std::unique_ptr<std::unordered_map<std::string,std::string>> data_;
};


#endif //PIGGYDB_KVSTORE_H
