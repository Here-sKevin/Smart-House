
#include "../HeaderFiles/Lampada.h"

lampada::lampada(string type, propriedade *l) : aparelho(type) {

    props.insert(pair<string,propriedade*>("luz",l));

}

lampada *lampada::clone() {
    return new lampada(*this);
}

void lampada::set_val_change(string cmd) {

    for(auto & prop : props) {
        if(cmd == "liga") {
            set_instance();
            if(prop.first == "luz") {
                if(!get_isOn() && cmd == "liga")
                    prop.second->set_valor(900);
            }
        }
        if(cmd == "desliga") {
            reset_instance();
            if(prop.first == "luz") {
                if(get_isOn() && cmd == "desliga")
                    prop.second->set_valor(-900);
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

void lampada::set_val_change_liga() {
    set_instance();
    for(auto & prop : props) {
        if (prop.first == "luz") {
            prop.second->set_valor(900);
        }
    }
}

void lampada::set_val_change_desliga() {

}

lampada::~lampada() = default;


