
#include "../HeaderFiles/Menor.h"


menor::menor(int idSensor, int val, string nome) : regra(idSensor, nome), valor(val) {}

menor::~menor() {}

bool menor::check_regra(int val) const {
    if(val < valor)
        return true;
    else
        return false;
}

bool menor::check_interval_regra(int val) const {
    return false;
}

menor *menor::clone() {
    return new menor(*this);
}
