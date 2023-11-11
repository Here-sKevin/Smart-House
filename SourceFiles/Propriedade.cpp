//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade(string type) {
    this->id.insert(pair<string,int>(type,0));
    this->has_sensor = false;
}

bool propriedade::get_sensor() const {
    return has_sensor;
}

void propriedade::set_sensor(bool sensor) {
    has_sensor = sensor;
}














