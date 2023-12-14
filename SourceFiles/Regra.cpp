
#include "../HeaderFiles/Regra.h"

int regra::id_regra=1;

regra::regra(int id_sensor) : id(get_id_regra()), id_sensor(id_sensor) {
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
