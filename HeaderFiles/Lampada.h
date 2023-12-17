
#ifndef POO_2324_LAMPADA_H
#define POO_2324_LAMPADA_H

#include "../HeaderFiles/Aparelho.h"

class lampada : public aparelho{
public:
    lampada(string cmd, string type);
    ~lampada();

    virtual void set_cmd(string comando) override;
private:
};

#endif //POO_2324_LAMPADA_H
