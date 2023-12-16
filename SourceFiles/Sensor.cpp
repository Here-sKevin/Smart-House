
#include "../HeaderFiles/Sensor.h"

int sensor::id_sensor = 1;

sensor::sensor(string cmd) : id(get_id_sensor()), has_prop(!(cmd == "")), prop(cmd) {
    set_id_sensor();
}

sensor::~sensor() {
    cout << "sensor destruido" << endl;
}

int sensor::get_id_sensor() {
    return id_sensor;
}

void sensor::set_id_sensor() {
    id_sensor++;
}

void sensor::set_regras_ids(int id) {
    regras_ids.push_back(id);
}

int sensor::get_id() const {
    return id;
}

void sensor::delete_regra_assoc(int id_regra) {
    int i = -1, index = -1;
    for(auto & id_regra_sensor : regras_ids) {
        i++;
        if(id_regra_sensor == id_regra){
            index = 1;
        }
    }
    if(index > -1) {
        regras_ids.erase(regras_ids.begin() + index);
    }
}

string sensor::get_prop() const {
    return prop;
}

