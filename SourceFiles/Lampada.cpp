
#include "../HeaderFiles/Lampada.h"

lampada::lampada(string type, propriedade *l) : aparelho(type) {

    props.insert(pair<string,propriedade*>("luz",l));

}

lampada *lampada::clone() {
    return new lampada(*this);
}

void lampada::set_val_change(string user_cmd,string cmd) {
    if(user_cmd != "acom")
        set_instance();
    for(auto & prop : props) {
        if(cmd == "liga") {
            if(prop.first == "luz") {
                if(!get_isOn() && cmd == "liga")
                    prop.second->set_valor(900);
            }
        }
        if(cmd == "desliga") {
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

lampada::~lampada() = default;


