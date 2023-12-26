
#ifndef POO_2324_RADIACAO_H
#define POO_2324_RADIACAO_H
#include "../HeaderFiles/Propriedade.h"

class radiacao : public propriedade {
public:
    radiacao(string type);
    ~radiacao();

private:
    int val_min;
};

#endif //POO_2324_RADIACAO_H
