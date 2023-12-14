
#include "../HeaderFiles/Processador.h"
#include "../HeaderFiles/Igual.h"
#include "../HeaderFiles/Menor.h"
#include "../HeaderFiles/Maior.h"
#include "../HeaderFiles/Entre.h"
#include "../HeaderFiles/Fora.h"

int processador::id_proc=1;

processador::processador(string cmd) : id(get_id_proc()), comando(cmd){
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



