
#include "../HeaderFiles/Som.h"



som::som() : propriedade(), val_min(0) {}


void som::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

void som::set_val_pmod(int v) {
    if(v >= val_min)
        this->set_new_val(v);
}

som::~som() = default;




