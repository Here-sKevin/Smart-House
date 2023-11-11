//
// Created by KevinRodrigues on 10/28/2023.
//

#include "../HeaderFiles/Processador.h"

processador::processador(int id) {
    this->id = id;
}

int processador::get_id() const {
    return id;
}

processador::~processador() {

}

void processador::add_regra(int id_regra, string cmd) {
    regras.push_back(new regra(id_regra,cmd));
}



