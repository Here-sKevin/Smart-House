
#include "../HeaderFiles/Humidade.h"


humidade::humidade() : propriedade(), val_min(0), val_max(100) {}

/*int humidade::get_val_min() const {
    return val_min;
}

int humidade::get_val_max() const {
    return val_max;
}*/

void humidade::set_valor(int v) {
    if(this->get_valor()+v >= val_min && this->get_valor()+v <= val_max)
        this->set_new_val(this->get_valor()+v);
}

humidade::~humidade() = default;





