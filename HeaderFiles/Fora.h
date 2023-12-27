
#ifndef POO_2324_FORA_H
#define POO_2324_FORA_H
#include "Regra.h"

class fora : public regra {
public:
    fora(string idSensor, int min, int max, string nome, sensor * sens);
    ~fora();
    bool check_regra(int val) const override;
    fora* clone() override;
private:
    int min;
    int max;
};


#endif //POO_2324_FORA_H
