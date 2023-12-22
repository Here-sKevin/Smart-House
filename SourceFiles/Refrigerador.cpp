
#include "../HeaderFiles/Refrigerador.h"

refrigerador::refrigerador(string type) : aparelho(type) {
    this->propsAlterLiga.insert(pair<string,int>("temperatura",1));
    this->propsAlterLiga.insert(pair<string,int>("som",20));
    this->propsAlterDesliga.insert(pair<string,int>("som",20));
}

bool refrigerador::check_prop_type(const string &cmd, const string &type) const {
    if(cmd == "liga") {
        for (auto itr = propsAlterLiga.begin(); itr != propsAlterLiga.end(); itr++) {
            if(itr->first == type){
                return true;
            }
        }
    }
    if(cmd == "desliga") {
        for (auto itr = propsAlterDesliga.begin(); itr != propsAlterDesliga.end(); itr++) {
            if(itr->first == type){
                return true;
            }
        }
    }
    return false;
}

int refrigerador::get_val(const string &cmd, const string &type) {
    if(cmd == "liga") {
        for (auto itr = propsAlterLiga.begin(); itr != propsAlterLiga.end(); itr++) {
            if(itr->first == type){
                return itr->second;
            }
        }
    }
    if(cmd == "desliga") {
        for (auto itr = propsAlterDesliga.begin(); itr != propsAlterDesliga.end(); itr++) {
            if(itr->first == type){
                return itr->second;
            }
        }
    }
    return false;
}

refrigerador *refrigerador::clone() {
    return new refrigerador(*this);
}

refrigerador::~refrigerador() = default;






