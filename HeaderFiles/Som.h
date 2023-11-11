//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_SOM_H
#define POO_2324_SOM_H
#include "../HeaderFiles/Propriedade.h"

class som : public propriedade {
public:
    som(string type);
private:
    int val_min = 0;
};

#endif //POO_2324_SOM_H
