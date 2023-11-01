//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Propriedade.h"


propriedade::propriedade(string type) {
    this->id.insert(pair<string,int>(type,0));
}

temperatura::temperatura(string type) : propriedade(type) {
    this->val_min = 0;
}

luz::luz(string type) : propriedade(type) {
    this->val_min = 0;
}

radiacao::radiacao(string type) : propriedade(type) {
    this->val_min = 0;
}

vibracao::vibracao(string type) : propriedade(type) {
    this->val_min = 0;
}

humidade::humidade(string type) : propriedade(type) {
    this->val_min = 0;
    this->val_max = 100;
}

fumo::fumo(string type) : propriedade(type) {
    this->val_min = 0;
    this->val_max = 100;
}

som::som(string type) : propriedade(type) {
    this->val_min = 0;
}
