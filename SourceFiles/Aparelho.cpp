
#include "../HeaderFiles/Aparelho.h"

int aparelho::id_aparelho = 1;

aparelho::aparelho(string type) : id(get_id_aparelho()), type(type) {
    set_id_aparelho();
}

aparelho::~aparelho() = default;

int aparelho::get_id() const {
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



