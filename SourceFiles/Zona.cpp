
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

string zona::list_zona_comp(int id) const {
    return {};
}

string zona::list_zona_prop(int id) const {
    return {};
}

void zona::mod_props(int id, string nome, int val) {

}

int zona::get_id() const {
    return this->id;
}

void zona::delete_comp(int id, char type, int id_comp) {

}

void zona::create_comp(string type, string cmd, int zone_id) {
    if(type == "s") {
        sensores.push_back(new sensor(cmd));
    }
    if(type == "p") {
        processadores.push_back(new processador(cmd, zone_id));
    }
    if(type == "a") {
        if(cmd == "aquecedor") {
            aparelhos.push_back(new aquecedor("desliga"));
        }
        if(cmd == "aspersor") {
            aparelhos.push_back(new aspersor("desliga"));
        }
        if(cmd == "refrigerador") {
            aparelhos.push_back(new refrigerador("desliga"));
        }
        if(cmd == "lampada") {
            aparelhos.push_back(new lampada("desliga"));
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
    propriedades.push_back(new temperatura("temperatura"));
    propriedades.push_back(new vibracao("vibracao"));
    propriedades.push_back(new luz("luz"));
    propriedades.push_back(new radiacao("radiacao"));
    propriedades.push_back(new humidade("humidade"));
    propriedades.push_back(new som("som"));
    propriedades.push_back(new fumo("fumo"));

}

zona::~zona() {
    for(auto & propriedade : propriedades) {
        delete propriedade;
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
                    processador->add_regra(regra, id_sensor, val1, val2);
                    // sensor->set_regras_ids(processador->get_last_id_regra());
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
    for(auto & sensor : sensores) {
        sensor->delete_regra_assoc(id_regra);
    }
}

void zona::set_prop(string nome, int valor) {
    for(auto & prop : propriedades) {
        if(prop->get_id_name(nome)){
            prop->set_id_val(nome,valor);
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
            processador->set_asoc_aparelho(id_aparelho);
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

void zona::send_cmd(int id_aparelho, string cmd) {

}

processador *zona::duplica(int id_proc, string nome) {
    for(auto & processador : processadores) {
        if(id_proc == processador->get_id()) {
            return new class processador(*processador, nome);
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
        processadores.push_back(new processador(p,""));
    }
    else{
        processadores.push_back(new processador(p,""));
    }
}

string zona::getAsStringProps() const {
    std::ostringstream os;
    for(auto & propriedade : propriedades) {
        os << "Propriedade: " << propriedade->get_type() <<
        " / valor: " << propriedade->get_value() << "\n";
    }
    return os.str();
}

string zona::getAsStringComp() const {
    std::ostringstream os;
    for(auto & sensor : sensores) {
        os << "s " << sensor->get_id() << " " << sensor->get_prop() << "\n";
    }
    for(auto & aparelho : aparelhos) {
        os << "a " << aparelho->get_id() << "\n";
    }
    for(auto & processador : processadores) {
        os << "p " << processador->get_id() << "\n";
    }

    return os.str();
}
