
#ifndef POO_2324_TEMPERATURA_H
#define POO_2324_TEMPERATURA_H
#include "Propriedade.h"

class temperatura : public propriedade {
public:
    temperatura(string type);
    ~temperatura();

private:
    int val_min;
};

#endif //POO_2324_TEMPERATURA_H
