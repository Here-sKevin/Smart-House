
#ifndef POO_2324_MENOR_H
#define POO_2324_MENOR_H
#include "Regra.h"

class menor : public regra{
public:
    menor(int idSensor, int val, string nome, sensor *sens);
    ~menor();
    virtual bool check_regra(int val) const override;
    virtual menor* clone() override;

private:
    int valor;
};

#endif //POO_2324_MENOR_H
