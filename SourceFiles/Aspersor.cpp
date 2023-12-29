
#include "../HeaderFiles/Aspersor.h"

aspersor::aspersor(string type, propriedade *h, propriedade *f) : aparelho(type), instanceAfterOff(0) {
    props.insert(pair<string,propriedade*>("humidade",h));
    props.insert(pair<string,propriedade*>("fumo",f));

}



aspersor *aspersor::clone() {
    return new aspersor(*this);
}

void aspersor::set_val_change(string cmd) {

    for(auto & prop : props) {
        if(cmd == "liga") {
            set_instance();
            set_instanceAfterOff(0);
            if(!get_isOn()) {
                if(get_instance() == 1){
                    if (prop.first == "humidade") {
                        prop.second->set_valor(50);
                    }
                    if (prop.first == "vibracao") {
                        prop.second->set_valor(100);
                    }
                }
                if(get_instance() == 2){
                    if (prop.first == "fumo") {
                        prop.second->set_valor(0);
                    }
                }

                if (get_instance() == 6) {
                    set_isOn();
                    if (prop.first == "vibracao") {
                        if (get_isOn() && cmd == "desliga")
                            prop.second->set_valor(-100);
                    }
                }
            }
        }
        if(cmd == "desliga") {
            reset_instance();
            set_instanceAfterOff(1);
            if(get_isOn()){
                if(prop.first == "vibracao") {
                    if(get_isOn() && cmd == "desliga")
                        prop.second->set_valor(-100);
                }
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

int aspersor::get_instanceAfterOff() const {
    return instanceAfterOff;
}

void aspersor::set_instanceAfterOff(int val) {
    instanceAfterOff = val;
}

void aspersor::set_val_change_liga() {

    set_instance();

    for(auto & prop : props) {
        if (prop.first == "humidade") {
            prop.second->set_valor(50);
        }
        if (prop.first == "fumo") {
            prop.second->set_valor(0);
        }
        if (prop.first == "vibracao") {
            prop.second->set_valor(100);
        }
    }
}

void aspersor::set_val_change_desliga() {
    if(get_instanceAfterOff() > 0 && get_instanceAfterOff() < 6) {
        set_instanceAfterOff(get_instanceAfterOff()+1);
        for(auto & prop : props) {
            if (!get_isOn()) {
                if (prop.first == "humidade") {
                    prop.second->set_valor(50);
                }
            }
        }
    }
}


aspersor::~aspersor() = default;





