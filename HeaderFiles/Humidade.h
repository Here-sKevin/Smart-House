//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_HUMIDADE_H
#define POO_2324_HUMIDADE_H
#include "../HeaderFiles/Propriedade.h"

class humidade : public propriedade {
public:
    humidade(string type);
private:
    int val_min = 0;
    int val_max = 100;
};

#endif //POO_2324_HUMIDADE_H
