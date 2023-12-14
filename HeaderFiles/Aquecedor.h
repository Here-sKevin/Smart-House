
#ifndef POO_2324_AQUECEDOR_H
#define POO_2324_AQUECEDOR_H
#include "../HeaderFiles/Aparelho.h"

class aquecedor : public aparelho{
public:
    aquecedor(string cmd);
    ~aquecedor();

    virtual void set_cmd(string comando) override;
private:
};

#endif //POO_2324_AQUECEDOR_H
