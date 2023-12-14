
#ifndef POO_2324_REGRA_H
#define POO_2324_REGRA_H
#include <string>
#include <iostream>

using namespace std;

class regra {
public:
    regra(int id_sensor);
    ~regra();
    int get_id() const;
    string get_cmd_regra() const;
    virtual bool check_regra(int val) const = 0;
    virtual bool check_interval_regra(int val) const = 0;

    static int get_id_regra();
    static void set_id_regra();
private:
    int id;
    int id_sensor;

    static int id_regra;
};

#endif //POO_2324_REGRA_H
