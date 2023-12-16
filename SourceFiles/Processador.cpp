
#include "../HeaderFiles/Processador.h"
#include "../HeaderFiles/Igual.h"
#include "../HeaderFiles/Menor.h"
#include "../HeaderFiles/Maior.h"
#include "../HeaderFiles/Entre.h"
#include "../HeaderFiles/Fora.h"

int processador::id_proc=1;

processador::processador(string cmd, int zone_id) : id(get_id_proc()), comando(cmd), id_aparelho(0), zona_id(zone_id){
    set_id_proc();
}

int processador::get_id() const {
    return id;
}

processador::~processador() {
    for(auto & regra : regras) {
        delete regra;
    }
    regras.clear();
}

void processador::add_regra(string cmd, int idSensor, int val1, int val2) {
    // regras.push_back(new regra(cmd));
    if(cmd == "igual_a"){
        regras.push_back(new igual(idSensor, val1));
    }
    if(cmd == "menor_que"){
        regras.push_back(new menor(idSensor, val1));
    }
    if(cmd == "maior_que") {
        regras.push_back(new maior(idSensor, val1));
    }
    if(cmd == "entre"){
        regras.push_back(new entre(idSensor, val1, val2));
    }
    if(cmd == "fora"){
        regras.push_back(new fora(idSensor, val1, val2));
    }
}

int processador::get_id_proc() {
    return id_proc;
}

void processador::set_id_proc() {
    id_proc++;
}

int processador::get_last_id_regra() {
    return regras[regras.size()-1]->get_id();
}

void processador::set_cmd(string cmd) {
    comando = cmd;
}

string processador::get_cmd() const {
    return comando;
}

void processador::delete_regra(int id_regra) {
    int i = -1, index = -1;
    for(auto & regra : regras) {
        i++;
        if(regra->get_id() == id_regra){
            index = i;
        }
    }
    if(index > -1) {
        delete regras[index];
        regras.erase(regras.begin() + i);
    }
}

void processador::set_asoc_aparelho(int id) {
    bool flag = false;
    for(auto & id_ap : id_aparelho) {
        if(id_ap == id){
            flag = true;
        }
    }
    if(!flag)
        id_aparelho.push_back(id);
}

void processador::set_ades_aparelho(int id) {
    int i = -1, index = -1;
    for(auto & id_ap : id_aparelho) {
        i++;
        if(id_ap == id){
            index = i;
        }
    }
    if(index > -1) {
        id_aparelho.erase(id_aparelho.begin() + i);
    }
}

processador::processador(const processador &o, string nome) {
    *this = o;
    this->nome = nome;
}

processador &processador::operator=(const processador &ref) {
    if(this != &ref) {
        id = ref.id;
        comando=ref.comando;
        zona_id = ref.zona_id;
        for(auto & refregras : ref.regras) {
           regras.push_back(refregras->clone());
        }
    }
    return *this;
}

string processador::get_nome_saved() const {
    return nome;
}

int processador::get_zona_asoc() const {
    return zona_id;
}



