
#include "../HeaderFiles/Regra.h"

int regra::id_regra=1;

regra::regra(int id_sensor, string nome) : id(get_id_regra()), id_sensor(id_sensor), nome(nome) {
    set_id_regra();
}

regra::~regra() {
    cout << "Regra destruida" << endl;
}

int regra::get_id() const {
    return id;
}

string regra::get_cmd_regra() const {
    // return comando;
    return nullptr;
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
    return id_sensor;
}

