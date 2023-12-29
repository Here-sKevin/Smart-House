
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
    string get_id() const; // retorna o id do processador
    string add_regra(const string& cmd, const string& IdSensor, int val1, int val2, sensor *sens); // adicion nova regra ao processador
    static int get_id_proc() ; // retorna id do processador
    static void set_id_proc(); // define id do processador
    void set_cmd(string cmd); // define comando do processador
    string get_cmd() const; // retorna comando atual do processador
    string delete_regra(int id_regra); // elimina regra associada ao processador
    string set_asoc_aparelho(const string& id, aparelho *p); // associa aparelho ao processador
    string set_ades_aparelho(const string& id); // desassocia aparelho ao processador
    processador& operator=(const processador& ref); // operador de associação por suporte ao cosntrutor por cópia
    int get_zona_asoc() const; // retorna zona em que o processador esta inserido (para fins de colocação do processador em memoria de volta ao simulador)
    string getAsStringRegras() const; // lista informação das regras do processador
    string exec_action(); // executa as ações de passagem de tempo
    int get_size_regras() const;
    string get_id_sensor(int position) const;
    void remove_regra(int position);
    bool check_asoc_regra_sensor(const string& id_s) const;
    bool check_asoc_proc_aparelho(const string& id_a) const;
    int get_id_regra(int position) const;
    int get_size_Allaparelhos() const;
    string get_id_aparelho(int position);
    bool get_activated() const;
    void set_activated(bool active);

private:
    string id;
    string comando;
    vector<regra*> regras;
    vector<aparelho*> AllAparelhos;
    bool activated;
    int zona_id;
    static int id_proc;
};

#endif //POO_2324_PROCESSADOR_H
