
#ifndef POO_2324_SOM_H
#define POO_2324_SOM_H
#include "../HeaderFiles/Propriedade.h"

class som : public propriedade {
public:
    som();
    ~som();
    void set_valor(int v) override;

private:
    int val_min;
};

#endif //POO_2324_SOM_H
