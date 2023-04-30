//
// Created by ame on 2023/4/30.
//

#include "KVstore.h"


KVstore::KVstore() {
    data_=std::make_unique<std::unordered_map<std::string,std::string>>();
}

void KVstore::Del(const std::string &key) {
     data_->erase(key);
}

std::optional<std::string> KVstore::Get(const std::string &key) {
    if(data_->contains(key)){
        return std::optional<std::string>((*data_)[key]);
    }
    else std::nullopt_t;
}

void KVstore::Put(const std::string &key, const std::string &val) {
    data_->insert({key,val});
}

KVstore::~KVstore() {

}
