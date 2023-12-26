
#ifndef POO_2324_SENSOR_H
#define POO_2324_SENSOR_H

#include "Propriedade.h"
#include <vector>

class sensor{
public:
    sensor(string cmd); // construtor com parametros
    ~sensor(); // destrutor por defeito
    int get_id() const; // retorna id do sensor
    static int get_id_sensor() ; // retorna o id dinamico a definir no novo sensor
    static void set_id_sensor(); // define o proximo id para um novo sensor
    string get_prop() const; // retorna a propriedade liga do sensor
    sensor* clone(); // retorna o objeto com um novo ponteiro

private:
    int id;
    string prop;
    static int id_sensor;
};

#endif //POO_2324_SENSOR_H
