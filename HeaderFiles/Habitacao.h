//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_HABITACAO_H
#define POO_2324_HABITACAO_H
#include <vector>
#include "Zona.h"
#include <string>
#include "../library/Terminal.h"


using namespace term;

using namespace std;

class habitacao {
public:
    habitacao(int linhas, int colunas); //Construtor com parametros de criacao do mapa com o tamanho indicado pelo utilizador
    ~habitacao();//Destrutor por defeito
    int get_linhas() const; // Devolve as linhas do mapa
    int get_colunas() const; // Devolve as colunas do mapa
    string list_zonas() const; // Lista informacao
    void create_zona(int x, int y, Terminal& t); //cria uma zona na limitacao do tamanho do mapa, indicado pelo utilizador
    void delete_zona(int id); //elimina zona pelo ID da zona
    bool state2create_zona(int x, int y) const; //Verifica se pode criar a zona nas coordenadas indicadas
    void cria_comp(int id, string c, string cmd); // Identificacao do component e chamada do construtor correspondente
    void draw_map(int x, int y); // desenha o mapa do simulador
    string to_string() const;
    int quant_zonas() const;

    int get_generate_id_zona() const;
    void set_generate_id_zona();
    bool can_draw_inGrid(int i, int j);
    int get_zona_id(int x, int y);

private:
    vector <zona*> zonas;
    int linhas;
    int colunas;
    int generate_id_zona;
};

#endif //POO_2324_HABITACAO_H
