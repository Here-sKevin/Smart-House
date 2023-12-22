
#include "../HeaderFiles/Lampada.h"

lampada::lampada(string type) : aparelho(type) {
    this->propsAlterLiga.insert(pair<string,int>("luz",900));
    this->propsAlterDesliga.insert(pair<string,int>("luz",900));
}

bool lampada::check_prop_type(const string &cmd, const string &type) const {
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

int lampada::get_val(const string &cmd, const string &type) {
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

lampada *lampada::clone() {
    return new lampada(*this);
}

lampada::~lampada() = default;


