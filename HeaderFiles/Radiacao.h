//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_RADIACAO_H
#define POO_2324_RADIACAO_H
#include "../HeaderFiles/Propriedade.h"

class radiacao : public propriedade {
public:
    radiacao(string type);
private:
    int val_min = 0;
};

#endif //POO_2324_RADIACAO_H
