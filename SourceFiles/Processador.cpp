
#include "../HeaderFiles/Processador.h"
#include "../HeaderFiles/Igual.h"
#include "../HeaderFiles/Menor.h"
#include "../HeaderFiles/Maior.h"
#include "../HeaderFiles/Entre.h"
#include "../HeaderFiles/Fora.h"
#include <sstream>

int processador::id_proc=1;

processador::processador(string cmd, int zone_id) : id("p" + to_string(generetedId())), comando(cmd), zona_id(zone_id){
    //set_id_proc();
}

string processador::get_id() const {
    return id;
}

processador::~processador() {
    for(auto & regra : regras) {
        delete regra;
    }
    regras.clear();
}

string processador::add_regra(const string& cmd, const string& idSensor, int val1, int val2, sensor *sens) {
    // regras.push_back(new regra(cmd));
    if(cmd == "igual_a"){
        regras.push_back(new igual(idSensor, val1, cmd,sens));
        return "Regra: igual_a foi adicionada\n";
    }
    if(cmd == "menor_que"){
        regras.push_back(new menor(idSensor, val1, cmd, sens));
        return "Regra: menor_que foi adicionada\n";
    }
    if(cmd == "maior_que") {
        regras.push_back(new maior(idSensor, val1, cmd, sens));
        return "Regra: maior_que foi adicionada\n";
    }
    if(cmd == "entre"){
        regras.push_back(new entre(idSensor, val1, val2, cmd, sens));
        return "Regra: entre foi adicionada\n";
    }
    if(cmd == "fora"){
        regras.push_back(new fora(idSensor, val1, val2, cmd, sens));
        return "Regra: fora foi adicionada\n";
    }
    return "Nao existe tipo de regra inserida\n";
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

string processador::delete_regra(int id_regra) {
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
        return "Regra foi eliminada\n";
    }
    return "Regra nao foi encontrada\n";
}

string processador::set_asoc_aparelho(const string& ida, aparelho *p) {
    bool flag = false;
    for(auto & Allapa : AllAparelhos) {
        if(Allapa->get_id() == ida){
            flag = true;
        }
    }
    if(!flag) {
        AllAparelhos.push_back(p);
        return "Aparelho foi associado ao processador\n";
    }
    return "Aparelho nao foi associado ao processador \n";

}

string processador::set_ades_aparelho(const string& id) {
    int i = -1, index = -1;
    for(auto & AllApa : AllAparelhos) {
        i++;
        if(AllApa->get_id() == id){
            index = i;
        }
    }
    if(index > -1) {
        AllAparelhos.erase(AllAparelhos.begin()+index);
        return "Aparelho foi desassociado do processador\n";
    }
    return "Aparelho nao foi desassociado do processador\n";
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

void processador::exec_action() {
    int denied = 0;
    for(auto & regra : regras) {
        if(!regra->check_regra_val()){
            denied++;
        }
    }
    if(denied == 0) {
        for(auto & aparelho : AllAparelhos) {
            aparelho->set_val_change("",get_cmd());
        }
    }
}

int processador::get_size_regras() const {
    return regras.size();
}

string processador::get_id_sensor(int position) const {
    return regras[position]->get_id_sensor_local();
}

void processador::remove_regra(int position) {
    delete regras[position];
    regras.erase(regras.begin()+position);
}

bool processador::check_asoc_regra_sensor(const string& id_s) const {
    for(auto & r : regras) {
        if(r->get_id_sensor_local() == id_s){
            return true;
        }
    }
    return false;
}

bool processador::check_asoc_proc_aparelho(const string& id_a) const {
    for(auto & all : AllAparelhos) {
        if(all->get_id() == id_a){
            return true;
        }
    }
    return false;
}





