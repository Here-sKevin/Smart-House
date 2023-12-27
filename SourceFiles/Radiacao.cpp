
#include "../HeaderFiles/Radiacao.h"

radiacao::radiacao() : propriedade(), val_min(0) {}

/*int radiacao::get_val_min() const {
    return val_min;
}

int radiacao::get_val_max() const {
    return 404;
}*/

void radiacao::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

radiacao::~radiacao() = default;





