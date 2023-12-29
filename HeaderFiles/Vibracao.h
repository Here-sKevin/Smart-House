
#ifndef POO_2324_VIBRACAO_H
#define POO_2324_VIBRACAO_H
#include "../HeaderFiles/Propriedade.h"

class vibracao : public propriedade {
public:
    vibracao();
    ~vibracao();
    void set_valor(int v) override;
    void set_val_pmod(int v) override;

private:
    int val_min;
};

#endif //POO_2324_VIBRACAO_H
