
#ifndef POO_2324_ENTRE_H
#define POO_2324_ENTRE_H
#include "Regra.h"

class entre : public regra {
public:
    entre(string idSensor, int min, int max, string nome, sensor *sens);
    ~entre();
    bool check_regra(int val) const override;
    virtual entre* clone() override;
private:
    int min;
    int max;
};

#endif //POO_2324_ENTRE_H
