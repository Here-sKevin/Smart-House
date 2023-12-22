
#ifndef POO_2324_REGRA_H
#define POO_2324_REGRA_H
#include <string>
#include <iostream>
#include "Sensor.h"

using namespace std;

class regra {
public:
    regra(int id_sensor, string nome, sensor *s);
    // regra(regra& o);
    ~regra();
    int get_id() const;
    virtual bool check_regra(int val) const = 0;
    virtual bool check_interval_regra(int val) const = 0;
    virtual regra* clone() = 0;

    static int get_id_regra();
    static void set_id_regra();

    string get_nome() const;
    int get_id_sensor() const;
private:
    int id;
    int id_sensor;
    sensor *s;

    string nome;

    static int id_regra;
};

#endif //POO_2324_REGRA_H
