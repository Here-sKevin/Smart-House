//
// Created by KevinRodrigues on 11/11/2023.
//
#include "../HeaderFiles/Humidade.h"


humidade::humidade(string type) : propriedade(type) {
    this->val_min = 0;
    this->val_max = 100;
}