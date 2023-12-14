
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

    bool can_draw_inGrid(int i, int j);
    int get_zona_id(int x, int y);

    void cria_regra(int id_zona, int id_proc, string regra, int id_sensor, int val1, int val2);
    void change_proc_cmd(int id_zona,int id_proc, string cmd);

    void delete_regra(int id_zona, int id_proc, int id_regra);

    void set_prop(int id_zona, string nome, int valor);

    void delete_comp(int id_zona, string type, int id);

private:
    vector <zona*> zonas;
    int linhas;
    int colunas;
};

#endif //POO_2324_HABITACAO_H
