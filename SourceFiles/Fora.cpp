
#include "../HeaderFiles/Fora.h"

fora::fora(int idSensor, int min, int max, string nome, sensor *sens) : regra(idSensor, nome, sens), min(min), max(max) {}

fora::~fora() {}

bool fora::check_regra(int val) const {
    if(val < min || val > max)
        return true;
    else
        return false;
}

fora *fora::clone() {
    return new fora(*this);
}
