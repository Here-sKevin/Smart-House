
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
    void create_comp(string type, string cmd, int zone_id); // cria componente na zona indicada
    int get_id() const; //devolve id da zona
    int get_x() const; // devolve a posicao x
    int get_y() const; // devolve a posicao y
    int get_quant_sensores() const; // devolve a quantidade de sensores na zona indicada
    int get_quant_aparelhos() const; // devolve a quantidade de aparelhos na zona indicada
    int get_quant_processadores() const;// devolve a quantidade de processadores na zona indicada
    void add_propriedades(); // adiciona propriedades a zona
    static int get_zona_id() ; // retorna id da zona indicada
    static void set_zona_id(); // define id da zona
    //void cria_regra(int id_proc, string regra, int id_sensor, int val1, int val2); // criação de uma nova regra
    void cria_regra(string id_proc, string regra, string id_sensor, int val1, int val2); // criação de uma nova regra
    //void change_proc_cmd(int id_proc, string cmd); // alteracao do comando do processador
    void change_proc_cmd(string id_proc, string cmd); // alteracao do comando do processador
    //void delete_regra(int id_proc, int id_regra); // elimina a regra indicada
    void delete_regra(string id_proc, int id_regra); // elimina a regra indicada
    void set_prop(string nome, int valor); // altera valor da propriedade
    //void delete_comp(string type, int id); // elimina componente indicado
    void delete_comp(string type, string id); // elimina componente indicado
    //void set_id_proc_aparelho(int id_proc, int id_aparelho); // associação do aparelho ao processador
    void set_id_proc_aparelho(const string& id_proc, const string& id_aparelho); // associação do aparelho ao processador
    //void remove_id_proc_aparelho(int id_proc, int id_aparelho); // desassocia aparelho do processador
    void remove_id_proc_aparelho(string id_proc, string id_aparelho); // desassocia aparelho do processador
    //processador* duplica(int id_proc); // retorna copia do objeto com novo ponteiro
    processador* duplica(string id_proc); // retorna copia do objeto com novo ponteiro
    void set_proc_saved(processador& p); // guarda processador em memoria
    string getAsStringProps() const; // lista informação das propriedades da zona indicada
    string getAsStringComp() const; // lista informação dos componentes da zona indicada
    //string getAsStringRegras(int id_proc) const; // lista informacao das regras do processador indicado
    string getAsStringRegras(string id_proc) const; // lista informacao das regras do processador indicado
    void exec_action(); // executa ações de passagem do tempo
    //void send_cmd_aparelho(string user_cmd,int id_aparelho,const string& comando); // envio manual do comando ao aparelho
    void send_cmd_aparelho(string user_cmd,string id_aparelho,const string& comando); // envio manual do comando ao aparelho

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
