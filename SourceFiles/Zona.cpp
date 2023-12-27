
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

void zona::create_comp(string type, string cmd, int zone_id) {
    if(type == "s") {
        propriedade *p;
        for(auto & prop : propriedades) {
            if(prop.first == cmd) {
                p = prop.second;
            }
        }
        sensores.push_back(new sensor(cmd, p));
    }
    if(type == "p") {
        processadores.push_back(new processador(cmd, zone_id));
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
        }
        if(cmd == "lampada") {
            propriedade *l;
            for(auto & prop : propriedades) {
                if(prop.first == "luz"){
                    l = prop.second;
                }
            }
            aparelhos.push_back(new lampada(cmd, l));
        }
    }
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

void zona::cria_regra(int id_proc, string regra, int id_sensor, int val1, int val2) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            for(auto & sensor : sensores) {
                if(sensor->get_id() == id_sensor) {
                    processador->add_regra(regra, id_sensor, val1, val2,  sensor);
                }
            }
        }
    }
}

void zona::change_proc_cmd(int id_proc, string cmd) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            processador->set_cmd(cmd);
        }
    }
}

void zona::delete_regra(int id_proc, int id_regra) {
    for(auto & processador : processadores) {
        if(processador->get_id() == id_proc) {
            processador->delete_regra(id_regra);
        }
    }
}

void zona::set_prop(string nome, int valor) {
    for(auto & prop : propriedades) {
        if(prop.first == nome) {
            prop.second->set_valor(valor);
        }
    }
}

void zona::delete_comp(string type, int id) {
    int i = -1, index = -1;
    if(type == "s") {
        for(auto & sensor : sensores) {
            i++;
            if(id == sensor->get_id()) {
                index = i;
            }
        }
        if(index > -1) {
            delete sensores[index];
            sensores.erase(sensores.begin() + i);
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
            processadores.erase(processadores.begin() + i);
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
            delete aparelhos[index];
            aparelhos.erase(aparelhos.begin() + i);
        }
    }
}

void zona::set_id_proc_aparelho(int id_proc, int id_aparelho) {
    for(auto & processador : processadores) {
        if(id_proc == processador->get_id()) {
            for(auto & aparelho: aparelhos) {
                if(id_aparelho == aparelho->get_id()) {
                    processador->set_asoc_aparelho(id_aparelho, aparelho);
                }

            }

        }
    }
}

void zona::remove_id_proc_aparelho(int id_proc, int id_aparelho) {
    for(auto & processador : processadores) {
        if(id_proc == processador->get_id()) {
            processador->set_ades_aparelho(id_aparelho);
        }
    }
}

processador *zona::duplica(int id_proc) {
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

string zona::getAsStringRegras(int id_proc) const {
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

void zona::send_cmd_aparelho(int id_aparelho, const string& comando) {
    for(auto & aparelho : aparelhos) {
        if(aparelho->get_id() == id_aparelho) {
            aparelho->set_val_change(comando);
        }
    }
}

