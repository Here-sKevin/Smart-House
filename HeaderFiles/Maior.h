
#ifndef POO_2324_MAIOR_H
#define POO_2324_MAIOR_H
#include "Regra.h"

class maior : public regra{
public:
    maior(int idSensor, int val, string nome, sensor *sens);
    ~maior();
    virtual bool check_regra(int val) const override;
    virtual maior* clone() override;

private:
    int valor;
};

#endif //POO_2324_MAIOR_H
