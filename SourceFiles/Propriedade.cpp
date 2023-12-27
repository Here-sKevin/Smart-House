
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade() : valor(0) {}

propriedade::~propriedade() {
    cout << "propriedade destruida" <<endl;
}

void propriedade::set_valor(int v) {
    valor = valor + v;
}

int propriedade::get_valor() const {
    return valor;
}

void propriedade::set_new_val(int v) {
    valor = v;
}
















