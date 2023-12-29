
#ifndef POO_2324_HUMIDADE_H
#define POO_2324_HUMIDADE_H
#include "../HeaderFiles/Propriedade.h"

class humidade : public propriedade {
public:
    humidade();
    ~humidade();
    void set_valor(int v) override;
    void set_val_pmod(int v) override;

private:
    int val_min = 0;
    int val_max = 100;
};

#endif //POO_2324_HUMIDADE_H
