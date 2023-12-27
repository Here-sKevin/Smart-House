
#ifndef POO_2324_AQUECEDOR_H
#define POO_2324_AQUECEDOR_H
#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class aquecedor : public aparelho{
public:
    aquecedor(string type, propriedade *t, propriedade *s);
    ~aquecedor();
    virtual aquecedor* clone();

    void set_val_change(string cmd) override;

private:
    //map<string, int> propsAlterLiga;
    //map<string, int> propsAlterDesliga;
    map<string, propriedade*> props;
};

#endif //POO_2324_AQUECEDOR_H
