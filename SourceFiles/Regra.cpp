//
// Created by KevinRodrigues on 11/11/2023.
//

#include "../HeaderFiles/Regra.h"

regra::regra(int id, string cmd) {
    this->id_regra=id;
    this->comando=cmd;
}

regra::~regra() {

}

int regra::get_id() const {
    return id_regra;
}

string regra::get_cmd_regra() const {
    return comando;
}