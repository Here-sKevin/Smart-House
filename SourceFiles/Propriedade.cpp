
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade(string type) : has_sensor(false) {
    this->id.insert(pair<string,int>(type,0));
}

bool propriedade::get_sensor() const {
    return has_sensor;
}

void propriedade::set_sensor(bool sensor) {
    has_sensor = sensor;
}

propriedade::~propriedade() {
    cout << "propriedade destruida" <<endl;
}

bool propriedade::get_id_name(string nome) const {
    if(id.find(nome) != id.end()) {
        return true;
    }
    else {
        return false;
    }
}

void propriedade::set_id_val(string nome, int valor) {
    id[nome] = valor;
}














