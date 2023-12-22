
#ifndef POO_2324_LUZ_H
#define POO_2324_LUZ_H

#include "../HeaderFiles/Propriedade.h"

class luz : public propriedade {
public:
    luz(string type);
    ~luz();
    void ativa_efeito(string cmd, int val) override;

private:
    int val_min = 0;
};

#endif //POO_2324_LUZ_H
