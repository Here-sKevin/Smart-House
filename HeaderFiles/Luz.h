
#ifndef POO_2324_LUZ_H
#define POO_2324_LUZ_H

#include "../HeaderFiles/Propriedade.h"

class luz : public propriedade {
public:
    luz();
    ~luz();
    void set_valor(int v) override;
    void set_val_pmod(int v) override;

private:
    int val_min;
};

#endif //POO_2324_LUZ_H
