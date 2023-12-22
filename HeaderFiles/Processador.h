
#ifndef POO_2324_PROCESSADOR_H
#define POO_2324_PROCESSADOR_H
#include <string>
#include "Sensor.h"
#include <vector>
#include "../HeaderFiles/Regra.h"
#include "Aparelho.h"

using namespace std;

class processador {
public:
    processador(string cmd, int zone_id);
    processador(const processador& o, string nome);
    ~processador();
    int get_id() const; // retorna o id do processador
    void add_regra(string cmd, int IdSensor, int val1, int val2, sensor *sens);
    static int get_id_proc() ;
    static void set_id_proc();

    void set_cmd(string cmd);
    string get_cmd() const;

    void delete_regra(int id_regra);

    void set_asoc_aparelho(int id, aparelho *p);
    void set_ades_aparelho(int id);

    processador& operator=(const processador& ref);

    string get_nome_saved() const;

    int get_zona_asoc() const;

    string getAsStringRegras() const;
    int get_Size_aparelhos() const;
    int get_aparelho_id(int position) const;

    int get_idSensor_regra(int position) const;
    int get_Size_regras() const;
    bool check_val_regra(int val, int regra_position) const;

private:
    int id;
    string comando;
    vector<regra*> regras;
    vector<aparelho*> AllAparelhos;
    string nome;
    int zona_id;

    static int id_proc;
};

#endif //POO_2324_PROCESSADOR_H
