
#include "../HeaderFiles/Vibracao.h"

vibracao::vibracao() : propriedade(), val_min(0) {}

/*int vibracao::get_val_min() const {
    return val_min;
}

int vibracao::get_val_max() const {
    return 404;
}*/

void vibracao::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

vibracao::~vibracao() = default;





