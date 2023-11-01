//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Zona.h"
#include <vector>

using namespace std;

string zona::list_zona_comp(int id) const {
    return {};
}

string zona::list_zona_prop(int id) const {
    return {};
}

void zona::mod_props(int id, string nome, int val) {

}

int zona::get_id() const {
    return this->id;
}

void zona::delete_comp(int id, char type, int id_comp) {

}

void zona::create_comp(string type, string cmd, int zone_id) {
    if(type == "s") {
        sensor s(zone_id, cmd);
        sensores.push_back(&s);
    }
    else if(type == "p") {

    }
    else {

    }
}

int zona::get_x() const {
    return x;
}

int zona::get_y() const {
    return y;
}

zona::zona(int id, int x, int y) {
    this->id = id;
    this->x = x;
    this->y = y;
}
