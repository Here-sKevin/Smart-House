//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_SENSOR_H
#define POO_2324_SENSOR_H

#include "Propriedade.h"

class sensor{
public:
    sensor(int id, string cmd);

private:
    int id;
    bool has_prop;
    string prop;
    // temperatura prop;
};

#endif //POO_2324_SENSOR_H
