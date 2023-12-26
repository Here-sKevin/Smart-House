
#ifndef POO_2324_SOM_H
#define POO_2324_SOM_H
#include "../HeaderFiles/Propriedade.h"

class som : public propriedade {
public:
    som(string type);
    ~som();

private:
    int val_min;
};

#endif //POO_2324_SOM_H
