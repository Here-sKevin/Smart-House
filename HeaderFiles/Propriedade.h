
#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>
#include <map>
#include <iostream>
#include "Aparelho.h"

using namespace std;

class propriedade{
public:
     propriedade();
     ~propriedade();
    int get_valor() const;
    virtual void set_valor(int v) = 0;
    void set_new_val(int v);

private:
    int valor;
};















#endif //POO_2324_PROPRIEDADE_H
