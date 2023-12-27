
#include "../HeaderFiles/Entre.h"

entre::entre(int idSensor, int min, int max, string nome, sensor *sens) : regra(idSensor, nome, sens), min(min), max(max) {}

entre::~entre() = default;

bool entre::check_regra(int val) const {
    if(val > min && val < max)
        return true;
    else
        return false;
}

entre *entre::clone() {
    return new entre(*this);
}
