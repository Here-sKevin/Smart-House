
#ifndef POO_2324_AQUECEDOR_H
#define POO_2324_AQUECEDOR_H
#include "../HeaderFiles/Aparelho.h"
#include "Propriedade.h"

class aquecedor : public aparelho{
public:
    aquecedor(string type, propriedade *t, propriedade *s);
    ~aquecedor();
    aquecedor* clone() override;
    void set_val_change(string user_cmd,string cmd) override;

private:
    map<string, propriedade*> props;
};

#endif //POO_2324_AQUECEDOR_H
