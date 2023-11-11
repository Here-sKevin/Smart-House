//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_PROCESSADOR_H
#define POO_2324_PROCESSADOR_H
#include <string>
#include "Sensor.h"
#include <vector>
#include "../HeaderFiles/Regra.h"

using namespace std;

class processador {
public:
    processador(int id);
    ~processador();
    int get_id() const; // retorna o id do processador
    void add_regra(int id, string cmd);
private:
    int id;
    vector<regra*> regras;
};

#endif //POO_2324_PROCESSADOR_H
