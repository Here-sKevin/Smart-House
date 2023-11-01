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
    zona(int id, int x, int y);
    string list_zona_comp(int id) const; // lista os componentes da zona
    string list_zona_prop(int id) const; // lista as propriedades da zona
    void mod_props(int id, string nome, int val); // modifica a propriedade
    void create_comp(string type, string cmd, int zone_id); // cria componente na zona indicada
    void delete_comp(int id, char type,int id_comp); // elimina componente
    int get_id() const; //devolve id da zona
    int get_x() const; // devolve a posicao x
    int get_y() const; // devolve a posicao y

private:
    vector<sensor*> sensores;
    vector<aparelho*> aparelhos;
    vector<processador*> processadores;
    // vector<propriedade> propriedades;
    int id;
    int x;
    int y;
};

#endif //POO_2324_ZONA_H
