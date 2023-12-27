
#ifndef POO_2324_VIBRACAO_H
#define POO_2324_VIBRACAO_H
#include "../HeaderFiles/Propriedade.h"

class vibracao : public propriedade {
public:
    vibracao();
    ~vibracao();
    //int get_val_min() const override;
    //int get_val_max() const override;
    void set_valor(int v) override;

private:
    int val_min;
};

#endif //POO_2324_VIBRACAO_H
