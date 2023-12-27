
#ifndef POO_2324_LUZ_H
#define POO_2324_LUZ_H

#include "../HeaderFiles/Propriedade.h"

class luz : public propriedade {
public:
    luz();
    ~luz();
    //int get_val_min() const override;
    //int get_val_max() const override;
    void set_valor(int v) override;

private:
    int val_min;
};

#endif //POO_2324_LUZ_H
