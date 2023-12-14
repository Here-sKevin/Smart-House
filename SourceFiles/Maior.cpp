
#include "../HeaderFiles/Maior.h"

maior::maior(int idSensor, int val) : regra(idSensor), valor(val) {}

maior::~maior() {}

bool maior::check_regra(int val) const {
    if(val > valor)
        return true;
    else
        return false;
}

bool maior::check_interval_regra(int val) const {
    return false;
}
