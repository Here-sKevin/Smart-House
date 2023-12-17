
#include "../HeaderFiles/Entre.h"

entre::entre(int idSensor, int min, int max, string nome) : regra(idSensor, nome), min(min), max(max) {}

entre::~entre() {}

bool entre::check_interval_regra(int val) const {
    if(val > min && val < max)
        return true;
    else
        return false;
}

bool entre::check_regra(int val) const {
    return false;
}

entre *entre::clone() {
    return new entre(*this);
}
