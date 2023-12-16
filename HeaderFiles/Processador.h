
#ifndef POO_2324_PROCESSADOR_H
#define POO_2324_PROCESSADOR_H
#include <string>
#include "Sensor.h"
#include <vector>
#include "../HeaderFiles/Regra.h"

using namespace std;

class processador {
public:
    processador(string cmd, int zone_id);
    processador(const processador& o, string nome);
    ~processador();
    int get_id() const; // retorna o id do processador
    void add_regra(string cmd, int IdSensor, int val1, int val2);
    int get_last_id_regra();
    static int get_id_proc() ;
    static void set_id_proc();

    void set_cmd(string cmd);
    string get_cmd() const;

    void delete_regra(int id_regra);

    void set_asoc_aparelho(int id);
    void set_ades_aparelho(int id);

    processador& operator=(const processador& ref);

    string get_nome_saved() const;

    int get_zona_asoc() const;

private:
    int id;
    string comando;
    vector<regra*> regras;
    vector<int> id_aparelho;
    string nome;
    int zona_id;

    static int id_proc;
};

#endif //POO_2324_PROCESSADOR_H
