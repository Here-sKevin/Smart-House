
#include "../HeaderFiles/Habitacao.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

habitacao::habitacao(int linhas, int colunas) : linhas(linhas), colunas(colunas) {}

habitacao::~habitacao() {
    for(auto & zona : zonas) {
        delete zona;
    }
    zonas.clear();
}

int habitacao::get_linhas() const {
    return this->linhas;
}

int habitacao::get_colunas() const {
    return this->colunas;
}

string habitacao::create_zona(int x, int y) {
    if(state2create_zona(x,y)){
        zonas.push_back(new zona(x, y));
        zonas[zonas.size()-1]->add_propriedades();
        return "Zona criada!\n";
    }
    else {
        return "Nao e possivel criar zona nestas coordenadas!\n";
    }
}

string habitacao::delete_zona(int id) {
    int i = -1, index;
    bool can_delete = false;
    for(const auto& zona : zonas) {
        i++;
        if(zona->get_id() == id) {
            can_delete = true;
            index = i;

        }
    }
    if(can_delete) {
        delete zonas[index];
        zonas.erase(zonas.begin()+index);
        return "Zona eliminada!\n";
    }
    else {
        return"Zona com o id inserido nao existe!\n";
    }
}

bool habitacao::state2create_zona(int x, int y) const {
    if(x <= get_linhas() && y <= get_colunas()) {
        bool can_create = true;
        for(const auto& zona : zonas){
                if(zona->get_x() == x && zona->get_y() == y) {
                    can_create = false;
                }
        }
        return can_create;
    }
    else
        return false;
}

string habitacao::cria_comp(int id, const string& c, const string& cmd) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id) {
           return zona->create_comp(c, cmd, id);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::to_string() const {
    ostringstream out;
    for(const auto& zona : zonas){
        out << "Zona com id: " << zona->get_id() << "\n" <<
        " Tem " << zona->get_quant_sensores() << " sensores; " << "\n" <<
        " Tem " << zona->get_quant_aparelhos() << " aparelhos; " << "\n" <<
        " Tem " << zona->get_quant_processadores() << " processadores; " <<"\n" <<
        "\n";
    }
    return out.str();
}

int habitacao::quant_zonas() const {
    return zonas.size();
}

bool habitacao::can_draw_inGrid(int i, int j) {
    for(auto & zona : zonas) {
        if(zona->get_x() == i && zona->get_y() == j){
            return true;
        }
    }
    return false;
}

int habitacao::get_zona_id(int x, int y) {
    for(auto & zona : zonas) {
        if(zona->get_x() == x && zona->get_y() == y){
            return zona->get_id();
        }
    }
    return 0;
}

string habitacao::cria_regra(int id_zona, const string& id_proc, const string& regra, const string& id_sensor, int val1, int val2) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->cria_regra(id_proc, regra, id_sensor, val1, val2);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::change_proc_cmd(int id_zona, const string& id_proc, const string& cmd) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->change_proc_cmd(id_proc, cmd);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::delete_regra(int id_zona, const string& id_proc, int id_regra) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->delete_regra(id_proc, id_regra);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::set_prop(int id_zona, const string& nome, int valor) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->set_prop(nome, valor);
        }
    }
    return "Propriedades adicionadas a zona\n";
}

string habitacao::delete_comp(int id_zona, const string& type, const string& id) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->delete_comp(type,id);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::set_id_aparelho_proc(int zona_id, const string& id_proc, const string& id_aparelho) {
    for(auto & zona : zonas) {
        if(zona->get_id() == zona_id) {
            return zona->set_id_proc_aparelho(id_proc,id_aparelho);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::remove_id_aparelho_proc(int zona_id, const string& id_proc, const string& id_aparelho) {
    for(auto & zona : zonas) {
        if(zona->get_id() == zona_id) {
            return zona->remove_id_proc_aparelho(id_proc,id_aparelho);
        }
    }
    return "Zona indicada nao existe\n";
}

string habitacao::send_cmd(const string& user_cmd, int id_zona, const string& id_aparelho, const string& comando) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->send_cmd_aparelho(user_cmd,id_aparelho,comando);
        }
    }
    return "Zona indicada nao existe\n";
}

processador *habitacao::duplica_processador(int id_zona, const string& id_proc) {

    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->duplica_processador(id_proc);
        }
    }

    return nullptr;
}

void habitacao::set_proc_saved(processador &p) {
    for(auto & zona : zonas) {
        if(zona->get_id() == p.get_zona_asoc()) {
            zona->set_proc_saved(p);
        }
    }
}

string habitacao::getAsStringProps() const {

    for(auto & zona : zonas) {
        if(zona->get_id() == get_srczona()) {
            return zona->getAsStringProps();
        }
    }

    return "" ;
}

int habitacao::get_srczona() const {
    return srczona;
}

void habitacao::set_srczona(int zona) {
    srczona = zona;
}

string habitacao::getAsStringComp() const {
    for(auto & zona : zonas) {
        if(zona->get_id() == get_srczona()) {
            return zona->getAsStringComp();
        }
    }
    return "";
}

string habitacao::getAsStringRegras(int id_zona, const string& id_proc) const {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->getAsStringRegras(id_proc);
        }
    }
    return "";
}

void habitacao::exec_action() {
    for(auto & zona : zonas) {
       zona->exec_action();
    }
}










