//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_ZONA_H
#define POO_2324_ZONA_H
#include "Sensor.h"
#include "Aparelho.h"
#include "Processador.h"
#include "Propriedade.h"
#include <string>
#include <vector>

using namespace std;

class zona {
public:
    string list_zona_comp(int id) const; // lista os componentes da zona
    string list_zona_prop(int id) const; // lista as propriedades da zona
    void mod_props(int id, string nome, int val); // modifica a propriedade
    void create_comp(int id, char type, string cmd); // cria componente na zona indicada
    void delete_comp(int id, char type,int id_comp); // elimina componente
    int get_id() const; //devolve id da zona

private:
    vector<sensor*> sensor;
    vector<aparelho*> aparelho;
    vector<processador*> processador;
    vector<propriedade*> propriedade;
    int id;
};

#endif //POO_2324_ZONA_H
