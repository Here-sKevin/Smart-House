
#ifndef POO_2324_PROCESSADOR_H
#define POO_2324_PROCESSADOR_H
#include <string>
#include "Sensor.h"
#include <vector>
#include "../HeaderFiles/Regra.h"
#include "Aparelho.h"

using namespace std;

class processador : componente {
public:
    processador(string cmd, int zone_id); // construtor com parametros
    processador(const processador& o); // construtor por cópia
    ~processador(); // destrutor por defeito
    //int get_id() const; // retorna o id do processador
    string get_id() const; // retorna o id do processador
    //void add_regra(string cmd, int IdSensor, int val1, int val2, sensor *sens); // adicion nova regra ao processador
    void add_regra(string cmd, string IdSensor, int val1, int val2, sensor *sens); // adicion nova regra ao processador
    static int get_id_proc() ; // retorna id do processador
    static void set_id_proc(); // define id do processador
    void set_cmd(string cmd); // define comando do processador
    string get_cmd() const; // retorna comando atual do processador
    void delete_regra(int id_regra); // elimina regra associada ao processador
    //void set_asoc_aparelho(int id, aparelho *p); // associa aparelho ao processador
    //void set_ades_aparelho(int id); // desassocia aparelho ao processador
    void set_asoc_aparelho(string id, aparelho *p); // associa aparelho ao processador
    void set_ades_aparelho(string id); // desassocia aparelho ao processador
    processador& operator=(const processador& ref); // operador de associação por suporte ao cosntrutor por cópia
    int get_zona_asoc() const; // retorna zona em que o processador esta inserido (para fins de colocação do processador em memoria de volta ao simulador)
    string getAsStringRegras() const; // lista informação das regras do processador
    void exec_action(); // executa as ações de passagem de tempo

private:
    string id;
    //int id;
    string comando;
    vector<regra*> regras;
    vector<aparelho*> AllAparelhos;
    int zona_id;
    static int id_proc;
};

#endif //POO_2324_PROCESSADOR_H
