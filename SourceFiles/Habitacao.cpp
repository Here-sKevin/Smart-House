//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Habitacao.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

habitacao::habitacao(int linhas, int colunas) {
    this->linhas = linhas;
    this->colunas = colunas;

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

void habitacao::create_zona(int x, int y) {
    if(state2create_zona(x,y)){
        zonas.push_back(new zona(zonas.size() + 1, x, y));
    }
    else {
        cout << "Nao e possivel criar zona nestas coordenadas!" << endl;
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







