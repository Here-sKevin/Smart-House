
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
    void create_zona(int x, int y, Terminal& t); //cria uma zona na limitacao do tamanho do mapa, indicado pelo utilizador
    void delete_zona(int id); //elimina zona pelo ID da zona
    bool state2create_zona(int x, int y) const; //Verifica se pode criar a zona nas coordenadas indicadas
    void cria_comp(int id, string c, string cmd); // Identificacao do component e chamada do construtor correspondente
    string to_string() const; // lista os sensores/aparelhos/processadores das zonas existentes
    int quant_zonas() const; // retorna a quantidade de zonas existentes
    bool can_draw_inGrid(int i, int j); // verifica se pode colocar a zona nas coordenadas indicadas
    int get_zona_id(int x, int y); // retorna o id da zona indicada
    void cria_regra(int id_zona, int id_proc, string regra, int id_sensor, int val1, int val2); // primeira camada para criação de uma regra
    void change_proc_cmd(int id_zona,int id_proc, string cmd); // altera o comando do processador indicado
    void delete_regra(int id_zona, int id_proc, int id_regra); // elimina regra indicada
    void set_prop(int id_zona, string nome, int valor); // altera valor da propriedade indicada
    void delete_comp(int id_zona, string type, int id); // elimina componente indicado
    void set_id_aparelho_proc(int zona_id, int id_proc, int id_aparelho); //associacao do aparelho ao processador
    void remove_id_aparelho_proc(int zona_id, int id_proc, int id_aparelho); //desassociacao do aparelho ao processador
    void send_cmd(int id_zona, int id_aparelho, string comando); // comando manual ao aparelho
    processador* duplica(int id_zona, int id_proc); // retorna cópia do objeto com um novo ponteiro
    void set_proc_saved(processador& p); // guarda processador em memoria
    string getAsStringProps() const; // lista informacoes das propriedades da zona
    string getAsStringComp() const; // lista informações dos componentes da zona
    string getAsStringRegras(int id_zona, int id_proc) const; // lista a informacao das regras do processador indicado
    int get_srczona() const; // utils para indicacao da zona
    void set_srczona(int zona);//utilz para indicacao da zona
    void exec_action(); // executa açoes da passagem de tempo/instancia

private:
    vector <zona*> zonas;
    int linhas;
    int colunas;
    int srczona;
};

std::ostream& operator<<(std::ostream& out, const habitacao& h);

#endif //POO_2324_HABITACAO_H
