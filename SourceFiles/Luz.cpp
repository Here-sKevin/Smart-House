
#include "../HeaderFiles/Luz.h"

luz::luz() : propriedade(), val_min(0) {}

/*int luz::get_val_min() const {
    return val_min;
}

int luz::get_val_max() const {
    return 404;
}*/

void luz::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

luz::~luz() = default;





