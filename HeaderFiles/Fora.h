
#ifndef POO_2324_FORA_H
#define POO_2324_FORA_H
#include "Regra.h"

class fora : public regra {
public:
    fora(int idSensor, int min, int max);
    ~fora();
    virtual bool check_interval_regra(int val) const override;
    bool check_regra(int val) const override;
    virtual fora* clone() override;
private:
    int min;
    int max;
};


#endif //POO_2324_FORA_H
