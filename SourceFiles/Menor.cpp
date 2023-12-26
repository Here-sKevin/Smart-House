
#include "../HeaderFiles/Menor.h"


menor::menor(int idSensor, int val, string nome, sensor *sens) : regra(idSensor, nome, sens), valor(val) {}

menor::~menor() {}

bool menor::check_regra(int val) const {
    if(val < valor)
        return true;
    else
        return false;
}

menor *menor::clone() {
    return new menor(*this);
}
