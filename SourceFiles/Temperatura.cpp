
#include "../HeaderFiles/Temperatura.h"

temperatura::temperatura() : propriedade(), val_min(-273) {}

void temperatura::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

void temperatura::set_val_pmod(int v) {
    if(v >= val_min)
        this->set_new_val(v);
}

temperatura::~temperatura() = default;




