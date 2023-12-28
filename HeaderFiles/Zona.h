
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
    zona(int x, int y); // construtor com parametros
    ~zona(); // destrutor por defeito
    string create_comp(const string& type, const string& cmd, int zone_id); // cria componente na zona indicada
    int get_id() const; //devolve id da zona
    int get_x() const; // devolve a posicao x
    int get_y() const; // devolve a posicao y
    int get_quant_sensores() const; // devolve a quantidade de sensores na zona indicada
    int get_quant_aparelhos() const; // devolve a quantidade de aparelhos na zona indicada
    int get_quant_processadores() const;// devolve a quantidade de processadores na zona indicada
    void add_propriedades(); // adiciona propriedades a zona
    static int get_zona_id() ; // retorna id da zona indicada
    static void set_zona_id(); // define id da zona
    string cria_regra(const string& id_proc, const string& regra, const string& id_sensor, int val1, int val2); // criação de uma nova regra
    string change_proc_cmd(const string& id_proc, const string& cmd); // alteracao do comando do processador
    string delete_regra(const string& id_proc, int id_regra); // elimina a regra indicada
    void set_prop(const string& nome, int valor); // altera valor da propriedade
    string delete_comp(const string& type, const string& id); // elimina componente indicado
    string set_id_proc_aparelho(const string& id_proc, const string& id_aparelho); // associação do aparelho ao processador
    string remove_id_proc_aparelho(const string& id_proc, const string& id_aparelho); // desassocia aparelho do processador
    processador* duplica(const string& id_proc); // retorna copia do objeto com novo ponteiro
    void set_proc_saved(processador& p); // guarda processador em memoria
    string getAsStringProps() const; // lista informação das propriedades da zona indicada
    string getAsStringComp() const; // lista informação dos componentes da zona indicada
    string getAsStringRegras(const string& id_proc) const; // lista informacao das regras do processador indicado
    void exec_action(); // executa ações de passagem do tempo
    string send_cmd_aparelho(const string& user_cmd,const string& id_aparelho,const string& comando); // envio manual do comando ao aparelho

private:
    vector<sensor*> sensores;
    vector<aparelho*> aparelhos;
    map<string,propriedade*> propriedades;
    vector<processador*> processadores;
    int id;
    int x;
    int y;
    static int zona_id;
};

#endif //POO_2324_ZONA_H
