//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_VIBRACAO_H
#define POO_2324_VIBRACAO_H
#include "../HeaderFiles/Propriedade.h"

class vibracao : public propriedade {
public:
    vibracao(string type);
private:
    int val_min = 0;
};

#endif //POO_2324_VIBRACAO_H
