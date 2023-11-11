//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_TEMPERATURA_H
#define POO_2324_TEMPERATURA_H
#include "Propriedade.h"

class temperatura : public propriedade {
public:
    temperatura(string type);

    bool get_sensor() const;
    void set_sensor(bool sensor);
private:
    int val_min;
};

#endif //POO_2324_TEMPERATURA_H
