
#include "../HeaderFiles/Refrigerador.h"

refrigerador::refrigerador(string type, propriedade *t, propriedade *s) : aparelho(type) {
    props.insert(pair<string,propriedade*>("temperatura",t));
    props.insert(pair<string,propriedade*>("som",s));

    /*this->propsAlterLiga.insert(pair<string,int>("temperatura",-1));
    this->propsAlterLiga.insert(pair<string,int>("som",20));
    this->propsAlterDesliga.insert(pair<string,int>("som",-20));*/
}



refrigerador *refrigerador::clone() {
    return new refrigerador(*this);
}

void refrigerador::set_val_change(string cmd) {
    set_instance();
    for(auto & prop : props) {
        if(cmd == "liga") {
            if(prop.first == "temperatura") {
                if(get_instance()%3==0)
                    prop.second->set_valor(-1);
            }
            if(prop.first == "som") {
                if(!get_isOn() && cmd == "liga")
                    prop.second->set_valor(20);
            }
        }
        if(cmd == "desliga") {
            if(prop.first == "som") {
                if(get_isOn() && cmd == "desliga")
                    prop.second->set_valor(-20);
            }
        }
    }

    if(get_isOn() && cmd == "desliga"){
        set_isOn();
    }
    if(!get_isOn() && cmd == "liga") {
        set_isOn();
    }

}

refrigerador::~refrigerador() = default;






