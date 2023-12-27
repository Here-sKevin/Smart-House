
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade() {
    valor = 0;
}

propriedade::~propriedade() {
    cout << "propriedade destruida" <<endl;
}

/*bool propriedade::get_id_name(const string& nome) const {
    if(id.find(nome) != id.end()) {
        return true;
    }
    else {
        return false;
    }
}

void propriedade::set_id_val(const string& nome, int valor) {
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        if(itr->first == nome) {
            if(itr->second+valor >= this->get_val_min()) {
                if(this->get_val_max() != 404) {
                    if(itr->second+valor <= this->get_val_max()){
                        itr->second = itr->second + valor;
                    }
                }
                else{
                    itr->second = itr->second + valor;
                }
            }
        }
    }
}

int propriedade::get_value() const {
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        return itr->second;
    }
    return 0;
}

string propriedade::get_type() const {
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        return itr->first;
    }
    return "";
}

void propriedade::set_id_val_2(aparelho *p, int valor, const string& comando) {
    bool altera = false;
    p->set_instance();
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        if(itr->first == this->get_type()) {
            if(itr->second+valor >= this->get_val_min()) {
                if(this->get_val_max() != 404) {
                    if(itr->second+valor <= this->get_val_max()){
                        altera = true;
                        //itr->second = itr->second + valor;
                    }
                }
                else{
                    altera = true;
                    // itr->second = itr->second + valor;
                }
            }
        }
        if(altera){
            if(p->get_type() == "aquecedor") {
                if(this->get_type() == "temperatura") {
                    if(p->get_instance() <= 50){
                        if(p->get_instance() % 3 == 0 && comando == "liga"){
                            itr->second = itr->second + valor;
                        }
                    }
                }
                if(this->get_type() == "som") {
                    if(p->get_instance() == 1) {
                        itr->second = itr->second + valor;
                    }
                }
            }
            if(p->get_type() == "aspersor") {

            }
            if(p->get_type() == "refrigerador") {
                if(this->get_type() == "temperatura") {
                    if(p->get_instance() % 3 == 0 && comando == "liga"){
                        itr->second = itr->second + valor;
                    }
                }
                if(this->get_type() == "som") {
                    if(!p->get_isOn() && comando == "liga") {
                        itr->second = itr->second + valor;
                    }
                    if(p->get_isOn() && comando == "desliga") {
                        itr->second = itr->second + valor;
                    }
                }
            }
            if(p->get_type() == "lampada") {
                if(!p->get_isOn() && comando == "liga") {
                    itr->second = itr->second + valor;
                }
                if(p->get_isOn() && comando == "desliga") {
                    itr->second = itr->second + valor;
                }
            }
        }
    }

    if(p->get_isOn() && comando == "desliga"){
        p->set_isOn();
    }
    if(!p->get_isOn() && comando == "ligado") {
        p->set_isOn();
    }
}*/

void propriedade::set_valor(int v) {
    valor = valor + v;
}

int propriedade::get_valor() const {
    return valor;
}

void propriedade::set_new_val(int v) {
    valor = v;
}
















