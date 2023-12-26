
#include "../HeaderFiles/Sensor.h"

int sensor::id_sensor = 1;

sensor::sensor(string cmd) : id(get_id_sensor()), prop(cmd) {
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

int sensor::get_id() const {
    return id;
}

string sensor::get_prop() const {
    return prop;
}

sensor *sensor::clone() {
    return new sensor(*this);
}

