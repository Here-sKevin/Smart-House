
#include "../HeaderFiles/Luz.h"

luz::luz() : propriedade(), val_min(0) {}

void luz::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

void luz::set_val_pmod(int v) {
    if(v >= val_min)
        this->set_new_val(v);
}

luz::~luz() = default;





