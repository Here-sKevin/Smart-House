
#ifndef POO_2324_ASPERSOR_H
#define POO_2324_ASPERSOR_H

#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class aspersor : public aparelho{
public:
    aspersor(string type, propriedade *h, propriedade *f);
    ~aspersor();
    aspersor* clone() override;
    void set_val_change(string cmd) override;

private:
    map<string, propriedade*> props;
};

#endif //POO_2324_ASPERSOR_H
