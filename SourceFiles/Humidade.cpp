
#include "../HeaderFiles/Humidade.h"


humidade::humidade() : propriedade(), val_min(0), val_max(100) {}

void humidade::set_valor(int v) {
    if(this->get_valor()+v >= val_min && this->get_valor()+v <= val_max)
        this->set_new_val(this->get_valor()+v);
}

void humidade::set_val_pmod(int v) {
    if(v >= val_min && v <= val_max)
        this->set_new_val(v);
}

humidade::~humidade() = default;





