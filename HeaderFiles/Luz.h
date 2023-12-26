
#ifndef POO_2324_LUZ_H
#define POO_2324_LUZ_H

#include "../HeaderFiles/Propriedade.h"

class luz : public propriedade {
public:
    luz(string type);
    ~luz();

private:
    int val_min;
};

#endif //POO_2324_LUZ_H
