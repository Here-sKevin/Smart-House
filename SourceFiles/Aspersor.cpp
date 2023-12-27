
#include "../HeaderFiles/Aspersor.h"

aspersor::aspersor(string type, propriedade *h, propriedade *f) : aparelho(type) {
    props.insert(pair<string,propriedade*>("humidade",h));
    props.insert(pair<string,propriedade*>("fumo",f));

}



aspersor *aspersor::clone() {
    return new aspersor(*this);
}

void aspersor::set_val_change(string user_cmd,string cmd) {
    if(user_cmd != "acom")
        set_instance();
    for(auto & prop : props) {
        if(cmd == "liga") {
            if(!get_isOn() && cmd == "liga") {
                if(prop.first == "humidade") {
                    prop.second->set_valor(50);
                }
                if(prop.first == "fumo") {
                    prop.second->set_valor(0);
                }
                if(prop.first == "vibracao") {
                    prop.second->set_valor(100);
                }
            }
        }
        if(cmd == "desliga") {
            if(prop.first == "vibracao") {
                if(get_isOn() && cmd == "desliga")
                    prop.second->set_valor(-100);
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

aspersor::~aspersor() = default;





