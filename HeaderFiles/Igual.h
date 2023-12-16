
#ifndef POO_2324_IGUAL_H
#define POO_2324_IGUAL_H
#include "Regra.h"

class igual : public regra {
public:
    igual(int idSensor, int val);
    ~igual();
    virtual bool check_regra(int val) const override;
    bool check_interval_regra(int val) const override;
    virtual igual* clone() override;
private:
    int valor;
};


#endif //POO_2324_IGUAL_H
