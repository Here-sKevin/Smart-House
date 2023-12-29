
#ifndef POO_2324_RADIACAO_H
#define POO_2324_RADIACAO_H
#include "../HeaderFiles/Propriedade.h"

class radiacao : public propriedade {
public:
    radiacao();
    ~radiacao();
    void set_valor(int v) override;
    void set_val_pmod(int v) override;

private:
    int val_min;
};

#endif //POO_2324_RADIACAO_H
