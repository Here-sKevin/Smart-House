
#include "../HeaderFiles/Aquecedor.h"

aquecedor::aquecedor(string type, propriedade *t, propriedade *s) : aparelho(type) {

    props.insert(pair<string,propriedade*>("temperatura",t));
    props.insert(pair<string,propriedade*>("som",s));
}

aquecedor::~aquecedor() = default;

aquecedor *aquecedor::clone() {
    return new aquecedor(*this);
}

void aquecedor::set_val_change(string user_cmd,string cmd) {
    if(user_cmd != "acom")
        set_instance();
    for(auto & prop : props) {
        if(cmd == "liga") {
            if(prop.first == "temperatura") {
                if(get_instance()%3 == 0){
                    if(get_instance() <= 50) {
                        prop.second->set_valor(1);
                    }
                }
            }
            if(prop.first == "som") {
                if(get_instance() == 1)
                    prop.second->set_valor(5);
            }
        }
        if(cmd == "desliga") {
            if(prop.first == "som") {
                if(get_isOn() && cmd == "desliga")
                    prop.second->set_valor(-5);
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


