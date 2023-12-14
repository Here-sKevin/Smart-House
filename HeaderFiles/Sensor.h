
#ifndef POO_2324_SENSOR_H
#define POO_2324_SENSOR_H

#include "Propriedade.h"
#include <vector>

class sensor{
public:
    sensor(string cmd);
    ~sensor();

    void set_regras_ids(int id);
    int get_id() const;
    static int get_id_sensor() ;
    static void set_id_sensor();

    void delete_regra_assoc(int id_regra);

private:
    int id;
    bool has_prop;
    string prop;
    vector<int> regras_ids;
    static int id_sensor;
};

#endif //POO_2324_SENSOR_H
