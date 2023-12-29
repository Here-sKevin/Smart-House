
#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>
#include <map>
#include <iostream>
#include "Aparelho.h"

using namespace std;

class propriedade{
public:
     propriedade(); // construtor
     ~propriedade(); // destrutor
    int get_valor() const; // retorna o valor atual da propriedade
    virtual void set_valor(int v) = 0; // valida os limites do valor da propriedade (somatório)
    virtual void set_val_pmod(int v) = 0; // valida os limites do valor da propriedade (valor direto)
    void set_new_val(int v); // atualiza o valor da propriedade

private:
    int valor;
};















#endif //POO_2324_PROPRIEDADE_H
