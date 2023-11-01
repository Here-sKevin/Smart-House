//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_HABITACAO_H
#define POO_2324_HABITACAO_H
#include <vector>
#include "Zona.h"
#include <string>

using namespace std;

class habitacao {
public:
    habitacao(int linhas, int colunas); //Construtor com parametros de criacao do mapa com o tamanho indicado pelo utilizador
    ~habitacao();//Destrutor por defeito
    int get_linhas() const; // Devolve as linhas do mapa
    int get_colunas() const; // Devolve as colunas do mapa
    string list_zonas() const; // Lista informacao
    void create_zona(int x, int y); //cria uma zona na limitacao do tamanho do mapa, indicado pelo utilizador
    void delete_zona(int id); //elimina zona pelo ID da zona
    bool state2create_zona(int x, int y) const; //Verifica se pode criar a zona nas coordenadas indicadas
    void cria_comp(int id, string c, string cmd);
    void draw_map(int x, int y);

private:
    vector <zona*> zonas;
    int linhas;
    int colunas;
};

#endif //POO_2324_HABITACAO_H
