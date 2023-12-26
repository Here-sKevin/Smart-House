
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
    processador(string cmd, int zone_id); // construtor com parametros
    processador(const processador& o, string nome); // construtor por cópia
    ~processador(); // destrutor por defeito
    int get_id() const; // retorna o id do processador
    void add_regra(string cmd, int IdSensor, int val1, int val2, sensor *sens); // adicion nova regra ao processador
    static int get_id_proc() ; // retorna id do processador
    static void set_id_proc(); // define id do processador
    void set_cmd(string cmd); // define comando do processador
    string get_cmd() const; // retorna comando atual do processador
    void delete_regra(int id_regra); // elimina regra associada ao processador
    void set_asoc_aparelho(int id, aparelho *p); // associa aparelho ao processador
    void set_ades_aparelho(int id); // desassocia aparelho ao processador
    processador& operator=(const processador& ref); // operador de associação por suporte ao cosntrutor por cópia
    string get_nome_saved() const; // retorna nome indicado do processador guardado em memoria
    int get_zona_asoc() const; // retorna zona em que o processador esta inserido (para fins de colocação do processador em memoria de volta ao simulador)
    string getAsStringRegras() const; // lista informação das regras do processador
    int get_Size_aparelhos() const; // retorna quantidade de aparelhos associados ao processador
    int get_aparelho_id(int position) const; // retorna id do aparelho associado ao processador
    int get_idSensor_regra(int position) const; // retorna id do sensor associado a regra
    int get_Size_regras() const; // retorna quantidade de regras do processador
    bool check_val_regra(int val, int regra_position) const; // verificação se o valor esta entre os limites indicado na regra

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
