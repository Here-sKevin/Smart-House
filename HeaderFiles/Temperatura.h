
#ifndef POO_2324_TEMPERATURA_H
#define POO_2324_TEMPERATURA_H
#include "Propriedade.h"

class temperatura : public propriedade {
public:
    temperatura();
    ~temperatura();
    void set_valor(int v) override;

private:
    int val_min;
};

#endif //POO_2324_TEMPERATURA_H
