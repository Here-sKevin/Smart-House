
#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>
#include <map>
#include <iostream>

using namespace std;

class propriedade{
public:
     propriedade(string type);
     ~propriedade();
    bool get_id_name(string nome) const; // retona tipo de propriedade
    void set_id_val(string nome, int valor); // define valor da propriedade
    virtual void ativa_efeito(string cmd, int val) = 0; // TODO
    int get_value() const; // retorna valor da propriedade
    string get_type() const; // retorna tipo de propriedade
private:
    map<string, int> id;
};















#endif //POO_2324_PROPRIEDADE_H
