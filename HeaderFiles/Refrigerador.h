
#ifndef POO_2324_REFRIGERADOR_H
#define POO_2324_REFRIGERADOR_H

#include "../HeaderFiles/Aparelho.h"

class refrigerador : public aparelho{
public:
    refrigerador(string cmd, string type);
    ~refrigerador();

    virtual void set_cmd(string comando) override;
private:
};

#endif //POO_2324_REFRIGERADOR_H
