
#include "../HeaderFiles/Igual.h"

igual::igual(int idSensor, int val) : regra(idSensor), valor(val) {}

igual::~igual() {}

bool igual::check_regra(int val) const {
    if(val == valor)
        return true;
    else
        return false;
}

bool igual::check_interval_regra(int val) const {
    return false;
}

igual *igual::clone() {
    return new igual(*this);
}

