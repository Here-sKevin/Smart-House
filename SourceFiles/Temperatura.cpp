
#include "../HeaderFiles/Temperatura.h"

temperatura::temperatura() : propriedade(), val_min(0) {}

/*int temperatura::get_val_min() const {
    return val_min;
}

int temperatura::get_val_max() const {
    return 404;
}*/

void temperatura::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

temperatura::~temperatura() = default;




