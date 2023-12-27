
#ifndef POO_2324_LAMPADA_H
#define POO_2324_LAMPADA_H

#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class lampada : public aparelho{
public:
    lampada(string type, propriedade *l);
    ~lampada();
    lampada* clone() override;
    void set_val_change(string user_cmd,string cmd) override;

private:
    map<string, propriedade*> props;
};

#endif //POO_2324_LAMPADA_H
