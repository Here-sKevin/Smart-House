
#include "../HeaderFiles/Vibracao.h"

vibracao::vibracao() : propriedade(), val_min(0) {}


void vibracao::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

vibracao::~vibracao() = default;





