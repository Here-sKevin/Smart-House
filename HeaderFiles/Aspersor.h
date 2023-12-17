
#ifndef POO_2324_ASPERSOR_H
#define POO_2324_ASPERSOR_H

#include "../HeaderFiles/Aparelho.h"

class aspersor : public aparelho{
public:
    aspersor(string cmd, string type);
    ~aspersor();

    virtual void set_cmd(string comando) override;
private:
};

#endif //POO_2324_ASPERSOR_H
