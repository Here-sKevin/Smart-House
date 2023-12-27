
#ifndef POO_2324_REGRA_H
#define POO_2324_REGRA_H
#include <string>
#include <iostream>
#include "Sensor.h"

using namespace std;

class regra {
public:
    regra(string id_sensor, string nome, sensor *s); // construtor com parametros
    ~regra(); // destrutor por defeito
    int get_id() const; // retorna id da regra
    virtual bool check_regra(int val) const = 0; // verificacao se o valor esta entre os limites da regra
    virtual regra* clone() = 0; // retorna copia do objeto com novo ponteriro
    static int get_id_regra(); // retorna id dinamico a definir nas novas regras
    static void set_id_regra(); // define o proximo id de uma nova regra
    string get_nome() const; // retorna o nome da regra
    //int get_id_sensor() const; // retorna o id do sensor associado a regra
    string get_id_sensor() const; // retorna o id do sensor associado a regra
    bool check_regra_val() const; // verifica a validação da regra em questão

private:
    int id;
    //int id_sensor;
    string id_sensor;
    sensor *s;
    string nome;
    static int id_regra;
};

#endif //POO_2324_REGRA_H
