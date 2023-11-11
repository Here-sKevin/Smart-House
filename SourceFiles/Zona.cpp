//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Zona.h"
#include "../HeaderFiles/Propriedade.h"
#include "../HeaderFiles/Temperatura.h"
#include "../HeaderFiles/Vibracao.h"
#include "../HeaderFiles/Luz.h"
#include "../HeaderFiles/Radiacao.h"
#include "../HeaderFiles/Humidade.h"
#include "../HeaderFiles/Som.h"
#include "../HeaderFiles/Fumo.h"
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
        /*if(cmd == "temperatura"){
            for(int i=0; i < propriedades.size(); i++){
                propriedades[i].find(cmd);
            }
        }*/
        sensores.push_back(new sensor(get_generate_id_sensor(), cmd));
        set_generate_id_sensor();
        //propriedades.push_back(new temperatura(cmd));
    }
    else if(type == "p") {
        processadores.push_back(new processador(this->get_generate_id_proc()));
        processadores[processadores.size()-1]->add_regra(get_generate_id_regra(), cmd);
        set_generate_id_proc();
    }
    else {
        // aparelhos.push_back(new aparelho(get_generate_id_aparelho()));
        // set_generate_id_aparelho()
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
    this->generate_id_proc = 1;
    this->generate_id_aparelho = 1;
    this->generate_id_sensor = 1;
    this->generate_id_regra = 1;
}

int zona::get_quant_sensores() const {
    return sensores.size();
}

int zona::get_quant_aparelhos() const {
    return aparelhos.size();
}

int zona::get_quant_processadores() const {
    return processadores.size();
}

int zona::get_generate_id_proc() const {
    return generate_id_proc;
}

void zona::set_generate_id_proc() {
    generate_id_proc = generate_id_proc+1;
}

int zona::get_generate_id_sensor() const {
    return generate_id_sensor;
}

void zona::set_generate_id_sensor() {
    generate_id_sensor = generate_id_sensor + 1;
}

int zona::get_generate_id_aparelho() const {
    return generate_id_aparelho;
}

void zona::set_generate_id_aparelho() {
    generate_id_aparelho = generate_id_aparelho + 1;
}

int zona::get_generate_id_regra() const {
    return generate_id_regra;
}

void zona::set_generate_id_regra() {
    generate_id_regra = generate_id_regra + 1;
}

void zona::add_propriedades() {
    propriedades.push_back(new temperatura("temperatura"));
    propriedades.push_back(new vibracao("vibracao"));
    propriedades.push_back(new luz("luz"));
    propriedades.push_back(new radiacao("radiacao"));
    propriedades.push_back(new humidade("humidade"));
    propriedades.push_back(new som("som"));
    propriedades.push_back(new fumo("fumo"));

}
