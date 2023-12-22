
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
    zona(int x, int y);
    ~zona();
    void create_comp(string type, string cmd, int zone_id); // cria componente na zona indicada
    int get_id() const; //devolve id da zona
    int get_x() const; // devolve a posicao x
    int get_y() const; // devolve a posicao y
    int get_quant_sensores() const; // devolve a quantidade de sensores na zona indicada
    int get_quant_aparelhos() const; // devolve a quantidade de aparelhos na zona indicada
    int get_quant_processadores() const;// devolve a quantidade de processadores na zona indicada

    void add_propriedades();

    static int get_zona_id() ;
    static void set_zona_id();

    void cria_regra(int id_proc, string regra, int id_sensor, int val1, int val2);
    void change_proc_cmd(int id_proc, string cmd);

    void delete_regra(int id_proc, int id_regra);

    void set_prop(string nome, int valor);

    void delete_comp(string type, int id);

    void set_id_proc_aparelho(int id_proc, int id_aparelho);
    void remove_id_proc_aparelho(int id_proc, int id_aparelho);

    processador* duplica(int id_proc, string nome);

    void set_proc_saved(processador& p);

    string getAsStringProps() const;
    string getAsStringComp() const;
    string getAsStringRegras(int id_proc) const;

    void exec_action();

    void send_cmd_aparelho(int id_aparelho,string comando);

private:
    vector<sensor*> sensores;
    vector<aparelho*> aparelhos;
    vector<propriedade*> propriedades;
    vector<processador*> processadores;
    int id;
    int x;
    int y;

    static int zona_id;
};

#endif //POO_2324_ZONA_H
