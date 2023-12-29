
#include "../HeaderFiles/Aparelho.h"

int aparelho::id_aparelho = 1;

aparelho::aparelho(string type) : id("a" + to_string(generetedId())), type(type), instance(0), isOn(false) {
    //set_id_aparelho();
}

aparelho::~aparelho() = default;

string aparelho::get_id() const {
    return id;
}

int aparelho::get_id_aparelho() const {
    return id_aparelho;
}

void aparelho::set_id_aparelho() const {
    id_aparelho++;
}

string aparelho::get_type() const {
    return type;
}

int aparelho::get_instance() const {
    return instance;
}

void aparelho::set_instance() {
    instance++;
}

bool aparelho::get_isOn() const {
    return isOn;
}

void aparelho::set_isOn() {
    if(isOn) {
        isOn = false;
    }
    else{
        isOn = true;
    }
}

void aparelho::reset_instance() {
    instance = 0;
}




