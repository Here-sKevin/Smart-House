
#ifndef POO_2324_VIBRACAO_H
#define POO_2324_VIBRACAO_H
#include "../HeaderFiles/Propriedade.h"

class vibracao : public propriedade {
public:
    vibracao(string type);
    ~vibracao();
    void ativa_efeito(string cmd, int val) override;

private:
    int val_min = 0;
};

#endif //POO_2324_VIBRACAO_H
