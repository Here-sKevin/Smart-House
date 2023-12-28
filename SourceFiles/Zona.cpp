
#include "../HeaderFiles/Zona.h"
#include "../HeaderFiles/Propriedade.h"
#include "../HeaderFiles/Temperatura.h"
#include "../HeaderFiles/Vibracao.h"
#include "../HeaderFiles/Luz.h"
#include "../HeaderFiles/Radiacao.h"
#include "../HeaderFiles/Humidade.h"
#include "../HeaderFiles/Som.h"
#include "../HeaderFiles/Fumo.h"
#include "../HeaderFiles/Aquecedor.h"
#include "../HeaderFiles/Aspersor.h"
#include "../HeaderFiles/Refrigerador.h"
#include "../HeaderFiles/Lampada.h"
#include <vector>
#include <sstream>

using namespace std;

int zona::zona_id = 1;

int zona::get_id() const {
    return this->id;
}

string zona::create_comp(const string& type, const string& cmd, int zone_id) {
    if(type == "s") {
        propriedade *p;
        for(auto & prop : propriedades) {
            if(prop.first == cmd) {
                p = prop.second;
            }
        }
        sensores.push_back(new sensor(cmd, p));
        return "Sensor criado!\n";
    }
    if(type == "p") {
        processadores.push_back(new processador(cmd, zone_id));
        return "Processador criado!\n";
    }
    if(type == "a") {
        if(cmd == "aquecedor") {
            propriedade *t;
            propriedade *s;
            for(auto & prop : propriedades) {
                if(prop.first == "temperatura") {
                    t = prop.second;
                }
                if(prop.first == "som"){
                    s = prop.second;
                }
            }
            aparelhos.push_back(new aquecedor(cmd, t, s));
            return "Aquecedor criado!\n";
        }
        if(cmd == "aspersor") {
            propriedade *h;
            propriedade *f;
            for(auto & prop : propriedades) {
                if(prop.first == "humidade") {
                    h = prop.second;
                }
                if(prop.first == "fumo"){
                    f = prop.second;
                }
            }
            aparelhos.push_back(new aspersor(cmd, h, f));
            return "Aspersor criado!\n";
        }
        if(cmd == "refrigerador") {
            propriedade *t;
            propriedade *s;
            for(auto & prop : propriedades) {
                if(prop.first == "temperatura") {
                    t = prop.second;
                }
                if(prop.first == "som"){
                    s = prop.second;
                }
            }
            aparelhos.push_back(new refrigerador(cmd, t, s));
            return "Refrigerador criado!\n";
        }
        if(cmd == "lampada") {
            propriedade *l;
            for(auto & prop : propriedades) {
                if(prop.first == "luz"){
                    l = prop.second;
                }
            }
            aparelhos.push_back(new lampada(cmd, l));
            return "Lampada criado!\n";
        }
    }
    return "Tipo de componente indicado nao existe\n";
}

int zona::get_x() const {
    return x;
}

int zona::get_y() const {
    return y;
}

zona::zona(int x, int y) : id(get_zona_id()), x(x), y(y) {
    set_zona_id();
}

int zona::get_quant_sensores() const {
    return sensores.size();
}

int zona::get_quant_aparelhos() const {
    return aparelhos.size();
}

int zona::get_quant_processadores() const {
    return processadores.size();
}

void zona::add_propriedades() {
    propriedades.insert(pair<string,propriedade*>("temperatura", new temperatura()));
    propriedades.insert(pair<string,propriedade*>("vibracao", new vibracao()));
    propriedades.insert(pair<string,propriedade*>("luz", new luz()));
    propriedades.insert(pair<string,propriedade*>("radiacao", new radiacao()));
    propriedades.insert(pair<string,propriedade*>("humidade", new humidade()));
    propriedades.insert(pair<string,propriedade*>("som", new som()));
    propriedades.insert(pair<string,propriedade*>("fumo", new fumo()));

}

zona::~zona() {
    for(auto & propriedade : propriedades) {
        delete propriedade.second;

    }
    propriedades.clear();
    for(auto & processador : processadores) {
        delete processador;
    }
    processadores.clear();
    for(auto & sensor : sensores) {
        delete sensor;
    }
    sensores.clear();
    for(auto & aparelho : aparelhos) {
        delete aparelho;
    }
    aparelhos.clear();
}

int zona::get_zona_id() {
    return zona_id;
}

void zona::set_zona_id() {
    zona_id++;
}

string zona::cria_regra(const string& id_proc, const string& regra, const string& id_sensor, int val1, int val2) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            for(auto & sensor : sensores) {
                if(sensor->get_id() == id_sensor) {
                    return processador->add_regra(regra, id_sensor, val1, val2,  sensor);
                }
            }
        }
    }
    return "Sensor ou processador indicado nao existe na zona\n";
}

string zona::change_proc_cmd(const string& id_proc, const string& cmd) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            processador->set_cmd(cmd);
            return "Comando do processador foi alterado\n";
        }
    }
    return "Processador indicado nao existe na zona\n";
}

string zona::delete_regra(const string& id_proc, int id_regra) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            return processador->delete_regra(id_regra);
        }
    }
    return "Processador nao existe na zona\n";
}

void zona::set_prop(const string& nome, int valor) {
    for(auto & prop : propriedades) {
        if(prop.first == nome) {
             prop.second->set_valor(valor);
        }
    }
}

string zona::delete_comp(const string& type, const string& id) {
    int i = -1, index = -1;
    if(type == "s") {
        for(auto & sensor : sensores) {
            i++;
            if(id == sensor->get_id()) {
                index = i;
            }
        }
        if(index > -1) {
            bool flag=false;
            for(auto & proc : processadores){
                if(proc->check_asoc_regra_sensor(sensores[index]->get_id())){
                    flag = true;
                }
            }
            if(!flag){
                delete sensores[index];
                sensores.erase(sensores.begin() + index);
                return "Sensor eliminado com sucesso";
            }
            else{
                return "Existem dependencias, sensor nao foi eliminado";
            }
        }
        else{
            return "Sensor nao existe na zona";
        }
    }
    if(type == "p") {
        for(auto & processador : processadores) {
            i++;
            if(id == processador->get_id()) {
                index = i;
            }
        }
        if(index > -1) {
            delete processadores[index];
            processadores.erase(processadores.begin() + index);
            return "Processador eliminado com sucesso";
        }
        else{
            return "Processador nao existe na zona";
        }
    }
    if(type == "a") {
        for(auto & aparelho : aparelhos) {
            i++;
            if(id == aparelho->get_id()) {
                index = i;
            }
        }
        if(index > -1) {
            bool flag = false;
            for(auto & p:processadores){
                if(p->check_asoc_proc_aparelho(aparelhos[index]->get_id())){
                    flag = true;
                }
            }
            if(!flag){
                delete aparelhos[index];
                aparelhos.erase(aparelhos.begin() + index);
                return "Aparelho eliminado com sucesso";
            }
            else{
                return "Existem dependencias, aparelho nao foi eliminado";
            }
        }
        else{
            return "Aparelho nao existe na zona";
        }
    }
    return "O componente indicado nao existe";
}

string zona::set_id_proc_aparelho(const string& id_proc, const string& id_aparelho) {
    for(auto & processador : processadores) {
        if(id_proc == processador->get_id()) {
            for(auto & aparelho: aparelhos) {
                if(id_aparelho == aparelho->get_id()) {
                    return processador->set_asoc_aparelho(id_aparelho, aparelho);
                }
            }
        }
    }
    return "Aparelho ou processador indicado nao foi encontrado na zona\n";
}

string zona::remove_id_proc_aparelho(const string& id_proc, const string& id_aparelho) {
    for(auto & processador : processadores) {
        if(id_proc == processador->get_id()) {
            return processador->set_ades_aparelho(id_aparelho);
        }
    }
    return "Processador indicado nao se encontra na zona\n";
}

processador *zona::duplica_processador(const string& id_proc) {
    for(auto & proc : processadores) {
        if(id_proc == proc->get_id()) {
            return new processador(*proc);
        }
    }

    return nullptr;
}

void zona::set_proc_saved(processador &p) {
    bool flag = false;
    int i=-1, index=-1;

    for(auto & processador : processadores) {
        i++;
        if(processador->get_id() == p.get_id()) {
            flag = true;
            index = i;
        }
    }
    if(flag) {
        delete processadores[index];
        processadores.erase(processadores.begin() + i);
        processadores.push_back(new processador(p));

    }
    else{
        processadores.push_back(new processador(p));
    }
    bool exists = false;
    vector<int> positionR;
    for(int j = 0; j < processadores[processadores.size()-1]->get_size_regras(); j++) {
        for(auto & s: sensores){
            if(processadores[processadores.size()-1]->get_id_sensor(j) == s->get_id()){
                exists=true;
            }
        }
        if(!exists){
            positionR.push_back(j);
        }
        else{
            exists=false;
        }
    }
    if(!positionR.empty()){
        for(int k=0; k < positionR.size(); k++) {
            processadores[processadores.size()-1]->remove_regra(positionR[k]);
        }
    }
}

string zona::getAsStringProps() const {
    std::ostringstream os;
    for(auto & propriedade : propriedades) {
        os << "Propriedade: " << propriedade.first <<
        " / valor: " << propriedade.second->get_valor() << "\n";
    }
    return os.str();
}

string zona::getAsStringComp() const {
    std::ostringstream os;
    os << "Sensores\n";
    for(auto & sensor : sensores) {
        os << "s " << sensor->get_id() << " " << sensor->get_prop() << "\n";
    }
    os << "Aparelhos\n";
    for(auto & aparelho : aparelhos) {
        os << "a " << aparelho->get_id() << " " << aparelho->get_type() << "\n";
    }
    os << "Processadores\n";
    for(auto & processador : processadores) {
        os << "p " << processador->get_id() << "\n";
    }

    return os.str();
}

string zona::getAsStringRegras(const string& id_proc) const {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc){
            return processador->getAsStringRegras();
        }
    }
    return "";
}
void zona::exec_action() {
    for(auto & processador :  processadores) {
        processador->exec_action();
    }
}

string zona::send_cmd_aparelho(const string& user_cmd,const string& id_aparelho, const string& comando) {
    for(auto & aparelho : aparelhos) {
        if(aparelho->get_id() == id_aparelho) {
            aparelho->set_val_change(user_cmd,comando);
            return "Comando manual foi enviado\n";
        }
    }
    return "Aparelho indicado nao existe na zona\n";
}

