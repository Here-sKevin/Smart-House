
#include "../HeaderFiles/Aspersor.h"

aspersor::aspersor(string type) : aparelho(type) {
    this->propsAlterLiga.insert(pair<string,int>("humidade",50));
    this->propsAlterLiga.insert(pair<string,int>("vibracao",100));
    this->propsAlterLiga.insert(pair<string,int>("fumo",0));
    this->propsAlterDesliga.insert(pair<string,int>("vibracao",100));
}

bool aspersor::check_prop_type(const string &cmd, const string &type) const {
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

int aspersor::get_val(const string &cmd, const string &type) {
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

aspersor *aspersor::clone() {
    return new aspersor(*this);
}

aspersor::~aspersor() = default;





