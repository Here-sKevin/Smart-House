
#ifndef POO_2324_VIBRACAO_H
#define POO_2324_VIBRACAO_H
#include "../HeaderFiles/Propriedade.h"

class vibracao : public propriedade {
public:
    vibracao(string type);
    ~vibracao();

private:
    int val_min;
};

#endif //POO_2324_VIBRACAO_H
