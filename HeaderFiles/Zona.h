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
    ~zona();
    string list_zona_comp(int id) const; // lista os componentes da zona
    string list_zona_prop(int id) const; // lista as propriedades da zona
    void mod_props(int id, string nome, int val); // modifica a propriedade
    void create_comp(string type, string cmd, int zone_id); // cria componente na zona indicada
    void delete_comp(int id, char type,int id_comp); // elimina componente
    int get_id() const; //devolve id da zona
    int get_x() const; // devolve a posicao x
    int get_y() const; // devolve a posicao y
    int get_quant_sensores() const; // devolve a quantidade de sensores na zona indicada
    int get_quant_aparelhos() const; // devolve a quantidade de aparelhos na zona indicada
    int get_quant_processadores() const;// devolve a quantidade de processadores na zona indicada

    int get_generate_id_proc() const;
    void set_generate_id_proc();

    int get_generate_id_sensor() const;
    void set_generate_id_sensor();

    int get_generate_id_aparelho() const;
    void set_generate_id_aparelho();

    int get_generate_id_regra() const;
    void set_generate_id_regra();

    void add_propriedades();

private:
    vector<sensor*> sensores;
    vector<aparelho*> aparelhos;
    vector<propriedade*> propriedades;
    vector<processador*> processadores;
    int id;
    int x;
    int y;
    int generate_id_proc;
    int generate_id_sensor;
    int generate_id_aparelho;
    int generate_id_regra;
};

#endif //POO_2324_ZONA_H
