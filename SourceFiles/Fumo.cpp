
#include "../HeaderFiles/Fumo.h"


fumo::fumo() : propriedade(), val_min(0), val_max(100) {}

/*int fumo::get_val_min() const {
    return val_min;
}

int fumo::get_val_max() const {
    return val_max;
}*/

void fumo::set_valor(int v) {
    if(this->get_valor()+v >= val_min && this->get_valor()+v <= val_max){
        this->set_new_val(this->get_valor()+v);
    }
}

fumo::~fumo() = default;





