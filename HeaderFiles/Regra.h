//
// Created by KevinRodrigues on 11/11/2023.
//

#ifndef POO_2324_REGRA_H
#define POO_2324_REGRA_H
#include <string>

using namespace std;

class regra {
public:
    regra(int id_regra, string cmd);
    ~regra();
    int get_id() const;
    string get_cmd_regra() const;
private:
    int id_regra;
    string comando;
};

#endif //POO_2324_REGRA_H
