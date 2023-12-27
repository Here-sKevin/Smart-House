
#ifndef POO_2324_IGUAL_H
#define POO_2324_IGUAL_H
#include "Regra.h"

class igual : public regra {
public:
    igual(string idSensor, int val, string nome, sensor *sens);
    ~igual();
    bool check_regra(int val) const override;
    igual* clone() override;

private:
    int valor;
};


#endif //POO_2324_IGUAL_H
