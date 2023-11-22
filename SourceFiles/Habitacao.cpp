//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Habitacao.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

habitacao::habitacao(int linhas, int colunas) {
    this->linhas = linhas;
    this->colunas = colunas;
    this->generate_id_zona = 1;

    cout << "Habitacao criado com sucesso!" << endl;
}

habitacao::~habitacao() = default;

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
        zonas.push_back(new zona(get_generate_id_zona(), x, y));
        zonas[zonas.size()-1]->add_propriedades();
        set_generate_id_zona();
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
        zonas[index]->~zona();
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
        out << "Zona com id: " << zona->get_id() <<
        " Tem " << zona->get_quant_sensores() << " sensores; " <<
        " Tem " << zona->get_quant_aparelhos() << " aparelhos; " <<
        " Tem " << zona->get_quant_processadores() << " processadores; " <<
        "\n";
    }
    return out.str();
}

int habitacao::get_generate_id_zona() const {
    return generate_id_zona;
}

void habitacao::set_generate_id_zona() {
    generate_id_zona = generate_id_zona + 1;
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







