
#ifndef POO_2324_MAIOR_H
#define POO_2324_MAIOR_H
#include "Regra.h"

class maior : public regra{
public:
    maior(int idSensor, int val);
    ~maior();
    virtual bool check_regra(int val) const override;
    bool check_interval_regra(int val) const override;

private:
    int valor;
};

#endif //POO_2324_MAIOR_H
