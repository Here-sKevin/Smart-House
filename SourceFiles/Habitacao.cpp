
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

std::string habitacao::list_zonas() const {
    return {};
}

void habitacao::create_zona(int x, int y, Terminal& t) {
    if(state2create_zona(x,y)){
        zonas.push_back(new zona(x, y));
        zonas[zonas.size()-1]->add_propriedades();
    }
    else {
        t << move_to(70, 0) << "Nao e possivel criar zona nestas coordenadas!";
    }
}

void habitacao::delete_zona(int id) {
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
    }
    else {
        cout << "Zona com o id inserido nao existe!" << endl;
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

void habitacao::cria_comp(int id, string c, string cmd) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id) {
           zona->create_comp(c, cmd, id);
        }
    }
}

void habitacao::draw_map(int x, int y) {

    for (int i = 0; i < x * 2; i++)
    {
        for (int j = 0; j < y * 2; j++)
        {
            if (i % 2 == 0) {
                cout << " " << "";
            }
            else {
                if (j % 2 == 0) {
                    cout << " " << "";
                }
                else {
                    cout << "." << "";
                }
            }
            if (j + 1 == y * 2)
                cout << endl;
        }
    }

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

void habitacao::cria_regra(int id_zona, int id_proc, string regra, int id_sensor, int val1, int val2) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->cria_regra(id_proc, regra, id_sensor, val1, val2);
        }
    }
}

void habitacao::change_proc_cmd(int id_zona, int id_proc, string cmd) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->change_proc_cmd(id_proc, cmd);
        }
    }
}

void habitacao::delete_regra(int id_zona, int id_proc, int id_regra) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->delete_regra(id_proc, id_regra);
        }
    }
}

void habitacao::set_prop(int id_zona, string nome, int valor) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
           zona->set_prop(nome, valor);
        }
    }
}

void habitacao::delete_comp(int id_zona, string type, int id) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->delete_comp(type,id);
        }
    }
}

void habitacao::set_id_aparelho_proc(int zona_id, int id_proc, int id_aparelho) {
    for(auto & zona : zonas) {
        if(zona->get_id() == zona_id) {
            zona->set_id_proc_aparelho(id_proc,id_aparelho);
        }
    }
}

void habitacao::remove_id_aparelho_proc(int zona_id, int id_proc, int id_aparelho) {
    for(auto & zona : zonas) {
        if(zona->get_id() == zona_id) {
            zona->remove_id_proc_aparelho(id_proc,id_aparelho);
        }
    }
}

void habitacao::send_cmd(int id_zona, int id_aparelho, string comando) {
    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            zona->send_cmd_aparelho(id_aparelho,comando);
        }
    }
}

processador *habitacao::duplica(int id_zona, int id_proc, string nome) {

    for(auto & zona : zonas) {
        if(zona->get_id() == id_zona) {
            return zona->duplica(id_proc, nome);
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

string habitacao::getAsStringRegras(int id_zona, int id_proc) const {
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

std::ostream& operator<<(std::ostream& out, const habitacao& h)
{
    out << h.getAsStringProps();

    return out;
}









