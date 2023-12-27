
#include "../HeaderFiles/Processador.h"
#include "../HeaderFiles/Igual.h"
#include "../HeaderFiles/Menor.h"
#include "../HeaderFiles/Maior.h"
#include "../HeaderFiles/Entre.h"
#include "../HeaderFiles/Fora.h"
#include <sstream>

int processador::id_proc=1;

processador::processador(string cmd, int zone_id) : id(get_id_proc()), comando(cmd), zona_id(zone_id){
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

void processador::add_regra(string cmd, int idSensor, int val1, int val2, sensor *sens) {
    // regras.push_back(new regra(cmd));
    if(cmd == "igual_a"){
        regras.push_back(new igual(idSensor, val1, cmd,sens));
    }
    if(cmd == "menor_que"){
        regras.push_back(new menor(idSensor, val1, cmd, sens));
    }
    if(cmd == "maior_que") {
        regras.push_back(new maior(idSensor, val1, cmd, sens));
    }
    if(cmd == "entre"){
        regras.push_back(new entre(idSensor, val1, val2, cmd, sens));
    }
    if(cmd == "fora"){
        regras.push_back(new fora(idSensor, val1, val2, cmd, sens));
    }
}

int processador::get_id_proc() {
    return id_proc;
}

void processador::set_id_proc() {
    id_proc++;
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

void processador::set_asoc_aparelho(int ida, aparelho *p) {
    bool flag = false;
    for(auto & Allapa : AllAparelhos) {
        if(Allapa->get_id() == ida){
            flag = true;
        }
    }
    if(!flag) {
        AllAparelhos.push_back(p);
    }

}

void processador::set_ades_aparelho(int id) {
    int i = -1, index = -1;
    for(auto & AllApa : AllAparelhos) {
        i++;
        if(AllApa->get_id() == id){
            index = i;
        }
    }
    if(index > -1) {
        AllAparelhos.erase(AllAparelhos.begin()+index);
    }
}

processador::processador(const processador &o) {
    *this = o;
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

int processador::get_zona_asoc() const {
    return zona_id;
}

string processador::getAsStringRegras() const {
    std::ostringstream os;

    os << "Regras \n";
    for(auto & regra : regras) {
        os << "Id: " << regra->get_id() << " nome: " << regra->get_nome() << " SensorId: " << regra->get_id_sensor() << "\n";
    }
    return os.str();
}

int processador::get_aparelho_id(int position) const {
    return AllAparelhos[position]->get_id();
}

int processador::get_idSensor_regra(int position) const {
    return regras[position]->get_id_sensor();
}

int processador::get_Size_regras() const {
    return regras.size();
}

bool processador::check_val_regra(int val, int regra_position) const {
    return regras[regra_position]->check_regra(val);
}

int processador::get_Size_aparelhos() const {
    return AllAparelhos.size();
}

void processador::exec_action() {
    int denied = 0;
    for(auto & regra : regras) {
        if(!regra->check_regra_val()){
            denied++;
        }
    }
    if(denied == 0) {
        for(auto & aparelho : AllAparelhos) {
            aparelho->set_val_change(get_cmd());
        }
    }
}



