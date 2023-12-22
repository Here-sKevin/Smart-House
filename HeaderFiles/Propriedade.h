
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

    bool get_id_name(string nome) const;
    void set_id_val(string nome, int valor);

    virtual void ativa_efeito(string cmd, int val) = 0;
    int get_value() const;
    string get_type() const;


private:
    map<string, int> id;
};















#endif //POO_2324_PROPRIEDADE_H
