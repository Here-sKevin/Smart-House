
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
    //bool get_id_name(const string& nome) const; // retona tipo de propriedade
    //void set_id_val(const string& nome, int valor); // define valor da propriedade
    //void set_id_val_2(aparelho *p, int valor, const string& comando);
    //int get_value() const; // retorna valor da propriedade
    //string get_type() const; // retorna tipo de propriedade
    //virtual int get_val_min() const = 0; // retorna valor minimo da propriedade
    //virtual int get_val_max() const = 0; // retorna valor maximo da propriedade, quando aplicavel

    //---------------------------
    int get_valor() const;
    virtual void set_valor(int v) = 0;
    void set_new_val(int v);

private:
    int valor;
};















#endif //POO_2324_PROPRIEDADE_H
