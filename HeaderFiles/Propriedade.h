//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>
#include <map>

using namespace std;

class propriedade{
public:
     propriedade(string type);

    bool get_sensor() const;
    void set_sensor(bool sensor);

private:
    map<string, int> id;
    bool has_sensor;
};















#endif //POO_2324_PROPRIEDADE_H
