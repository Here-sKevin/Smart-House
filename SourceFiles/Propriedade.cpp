
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade(string type) {
    this->id.insert(pair<string,int>(type,0));
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

int propriedade::get_value() const {
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        return itr->second;
    }
    return 0;
}

string propriedade::get_type() const {
    for (auto itr = id.begin(); itr != id.end(); itr++) {
        return itr->first;
    }
    return "";
}














