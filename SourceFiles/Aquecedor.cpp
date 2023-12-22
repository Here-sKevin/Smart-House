
#include "../HeaderFiles/Aquecedor.h"

aquecedor::aquecedor(string type) : aparelho(type) {
    this->propsAlterLiga.insert(pair<string,int>("temperatura",1));
    this->propsAlterLiga.insert(pair<string,int>("som",5));
    this->propsAlterDesliga.insert(pair<string,int>("som",5));
}

aquecedor::~aquecedor() = default;


bool aquecedor::check_prop_type(const string& cmd, const string& type) const {
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

int aquecedor::get_val(const string &cmd, const string &type) {
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

aquecedor *aquecedor::clone() {
    return new aquecedor(*this);
}


