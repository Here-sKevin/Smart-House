
#include "../HeaderFiles/Som.h"



som::som() : propriedade(), val_min(0) {}

/*int som::get_val_min() const {
    return val_min;
}

int som::get_val_max() const {
    return 404;
}*/

void som::set_valor(int v) {
    if(this->get_valor()+v >= val_min)
        this->set_new_val(this->get_valor()+v);
}

som::~som() = default;




