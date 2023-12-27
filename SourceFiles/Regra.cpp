
#include "../HeaderFiles/Regra.h"

int regra::id_regra=1;

regra::regra(int id_sensor, string nome, sensor *s) : id(get_id_regra()), id_sensor(id_sensor), nome(nome), s(s) {
    set_id_regra();
}

regra::~regra() {
    cout << "Regra destruida" << endl;
}

int regra::get_id() const {
    return id;
}

int regra::get_id_regra() {
    return id_regra;
}

void regra::set_id_regra() {
    id_regra++;
}

string regra::get_nome() const {
    return nome;
}

int regra::get_id_sensor() const {
    // return id_sensor;
    return s->get_id();
}

bool regra::check_regra_val() const {
    return this->check_regra(s->get_prop_val());
}


