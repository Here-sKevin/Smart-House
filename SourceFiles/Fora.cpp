
#include "../HeaderFiles/Fora.h"

fora::fora(int idSensor, int min, int max) : regra(idSensor), min(min), max(max) {}

fora::~fora() {}

bool fora::check_interval_regra(int val) const {
    if(val < min || val > max)
        return true;
    else
        return false;
}

bool fora::check_regra(int val) const {
    return false;
}
