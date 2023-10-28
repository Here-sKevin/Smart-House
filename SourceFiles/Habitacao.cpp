//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Habitacao.h"
#include <iostream>

using namespace std;

habitacao::habitacao(int linhas, int colunas) {
    this->linhas = linhas;
    this->colunas = colunas;

    cout << "Habitação criado com sucesso!";
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
        //if( /* funcao para verificar se existe zona nestas coordenadas */ ) {
            // cria zona
        //}
    }
    else {
        cout << "Nao e possivel criar zona nestas coordenadas!" << endl;
    }
}

void habitacao::delete_zona(int id) {

}

bool habitacao::state2create_zona(int x, int y) const {
    if(x <= get_linhas() && y <= get_colunas())
        return true;
    else
        return false;
}







