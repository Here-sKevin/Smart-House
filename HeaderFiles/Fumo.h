
#ifndef POO_2324_FUMO_H
#define POO_2324_FUMO_H
#include "../HeaderFiles/Propriedade.h"


class fumo : public propriedade {
public:
    fumo(string type);
    ~fumo();

private:
    int val_min;
    int val_max;
};

#endif //POO_2324_FUMO_H
