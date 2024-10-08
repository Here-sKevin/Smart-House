
#include "../HeaderFiles/Refrigerador.h"

refrigerador::refrigerador(string type, propriedade *t, propriedade *s) : aparelho(type) {
    props.insert(pair<string,propriedade*>("temperatura",t));
    props.insert(pair<string,propriedade*>("som",s));
}



refrigerador *refrigerador::clone() {
    return new refrigerador(*this);
}

void refrigerador::set_val_change(string cmd) {

    if(cmd == "liga")
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
            reset_instance();
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

void refrigerador::set_val_change_liga() {
    set_instance();
    for(auto & prop : props) {
        if (prop.first == "temperatura") {
            if (get_instance() % 3 == 0)
                prop.second->set_valor(-1);
        }
        if (prop.first == "som") {
            if (!get_isOn())
                prop.second->set_valor(20);
        }

    }
}

void refrigerador::set_val_change_desliga() {

}

refrigerador::~refrigerador() = default;






