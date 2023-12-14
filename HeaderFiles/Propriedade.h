
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

    bool get_sensor() const;
    void set_sensor(bool sensor);

    bool get_id_name(string nome) const;
    void set_id_val(string nome, int valor);

    virtual void ativa_efeito(string cmd, string aparelho) = 0;

private:
    map<string, int> id;
    bool has_sensor;
};















#endif //POO_2324_PROPRIEDADE_H
