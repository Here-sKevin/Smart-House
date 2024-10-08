
#ifndef POO_2324_REFRIGERADOR_H
#define POO_2324_REFRIGERADOR_H

#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class refrigerador : public aparelho{
public:
    refrigerador(string type, propriedade *t, propriedade *s);
    ~refrigerador();
    refrigerador* clone() override;
    void set_val_change(string cmd) override;
    void set_val_change_liga() override;
    void set_val_change_desliga() override;

private:
    map<string, propriedade*> props;
};

#endif //POO_2324_REFRIGERADOR_H
