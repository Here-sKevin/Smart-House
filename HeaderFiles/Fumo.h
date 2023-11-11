//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_FUMO_H
#define POO_2324_FUMO_H
#include "../HeaderFiles/Propriedade.h"


class fumo : public propriedade {
public:
    fumo(string type);
private:
    int val_min = 0;
    int val_max = 100;
};

#endif //POO_2324_FUMO_H
