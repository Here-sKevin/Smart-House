
#ifndef POO_2324_LAMPADA_H
#define POO_2324_LAMPADA_H

#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class lampada : public aparelho{
public:
    lampada(string type, propriedade *l);
    ~lampada();
    virtual lampada* clone();

    void set_val_change(string cmd) override;

private:
    //map<string, int> propsAlterLiga;
    //map<string, int> propsAlterDesliga;
    map<string, propriedade*> props;
};

#endif //POO_2324_LAMPADA_H
