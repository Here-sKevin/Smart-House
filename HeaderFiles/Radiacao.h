
#ifndef POO_2324_RADIACAO_H
#define POO_2324_RADIACAO_H
#include "../HeaderFiles/Propriedade.h"

class radiacao : public propriedade {
public:
    radiacao(string type);
    ~radiacao();
    void ativa_efeito(string cmd, int val) override;
private:
    int val_min = 0;
};

#endif //POO_2324_RADIACAO_H
