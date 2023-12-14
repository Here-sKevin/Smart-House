
#ifndef POO_2324_SOM_H
#define POO_2324_SOM_H
#include "../HeaderFiles/Propriedade.h"

class som : public propriedade {
public:
    som(string type);
    ~som();
    void ativa_efeito(string cmd, string aparelho) override;
private:
    int val_min = 0;
};

#endif //POO_2324_SOM_H
