
#ifndef POO_2324_HUMIDADE_H
#define POO_2324_HUMIDADE_H
#include "../HeaderFiles/Propriedade.h"

class humidade : public propriedade {
public:
    humidade();
    ~humidade();
    //int get_val_min() const override;
    //int get_val_max() const override;
    void set_valor(int v) override;

private:
    int val_min = 0;
    int val_max = 100;
};

#endif //POO_2324_HUMIDADE_H
