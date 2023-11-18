//
// Created by KevinRodrigues on 10/24/2023.
//

#include "../HeaderFiles/Interface.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../library/Terminal.h"


using namespace term;

interface::interface() {

}

interface::~interface() {
    cout << "Destrutor Interface" << endl;
}

void interface::menu() {

    int option;
    cout <<endl<< "\t============================" << endl
         << "\t|| BEM-VINDO AO SIMULADOR ||" << endl
         << "\t|| 1 -> JOGAR             ||" << endl
         << "\t|| 2 -> SAIR              ||" << endl
         << "\t============================" << endl;

    cout << endl;
    cout << endl;
    cout << "Seleciona uma das opcoes apresentadas ( 1 - Para comecar o simulador / 2 - Para sair ): ";
    cin >> option;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cin >> option;
    }

    switch (option) {
        case 1:
            cout << "Simulador inicializado!" << endl;
            config();
            break;
        case 2:
            return;

        default:
            cout << "Opcao invalida \n";
            break;
    }
}
void print_size(Terminal& t) {
    std::ostringstream o;
    o << "tamanho do terminal: " << std::setw(7) << t.getNumCols() << "x" << t.getNumRows();
    std::string str = o.str();
    t.clear();
    t << set_color(0) << move_to(t.getNumCols()-str.length(), t.getNumRows()-1) << str;
}

void interface::config() {
    string line, cmd;
    bool flag = false;
    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    print_size(t);
    while (true) {
        start(flag, t);
        flag = true;
    }
}

bool interface::file_reader(const string& file_name, Terminal& t) {
    ifstream data(file_name);
    string line;

    if (!data.is_open()) {
        return false;
    }
    while (!data.eof()) {
        getline(data, line);
        istringstream in(line);
        string cmd; in >> cmd;
        //cmd_validator(line);
        cmd_validator(line, t);
    }
    data.close();
    return true;
}

void interface::cmd_validator(const string& line, Terminal& t) {
    if (line.empty())
        return;

    istringstream in(line);
    string cmd;
    t.clear();

    in >> cmd;
    if(map || cmd == "hnova" || cmd == "exec" || cmd == "sair") {
        if(cmd == "prox") {

        }
        else if(cmd == "avanca") {
            int param;
            in >> param;

        }
        else if(cmd == "hnova"){
            int paraml, paramc;
            in >> paraml;
            in >> paramc;
            if(paraml != 0 && paramc != 0) {
                // set_info_lines();
                t << move_to(80, get_info_lines()) << "Parametros validados com sucesso";

                // cout << "Parametros validados com sucesso" << endl;
                if((paraml >= 2 && paraml <= 4) && (paramc >= 2 && paramc <= 4)){
                    if(!get_map_state()) {
                        habit = new habitacao(paraml,paramc);
                        set_map_state(true);
                        habit->draw_map(paraml, paramc);
                    }
                    else{
                        // set_info_lines();
                        t << move_to(80, get_info_lines()) << "Habitacao ja criada";
                    }
                }
                else {
                    // set_info_lines();
                    t << move_to(80, get_info_lines()) << "A habitacao devera ter um tamanho minimo";
                    // set_info_lines();
                    t << move_to(80, get_info_lines()) << "de 2x2 e maximo de 4x4";
                }
            }
            else{
                // set_info_lines();
                t << move_to(80, get_info_lines()) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "hrem") {
            habit->~habitacao();
            set_map_state(false);
        }
        else if(cmd == "znova"){

            int paraml, paramc;
            in >> paraml;
            in >> paramc;

            if(paraml != 0 && paramc != 0) {
                cout << "Parametros validados com sucesso" << endl;
                habit->create_zona(paraml, paramc);
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "zrem") {
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso" << endl;
                habit->delete_zona(param);
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "zlista"){
            cout << habit->to_string();
        }
        else if(cmd == "zcomp") {
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "zprops"){
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "pmod") {
            int param1,param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && param3 != 0) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }

        }
        else if(cmd == "cnovo"){
            int param1;
            string param2;
            string param3;

            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                cout << "Parametros validados com sucesso"<< endl;
                habit->cria_comp(param1, param2, param3);
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "crem") {
            int param1, param3;
            char param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "rnova"){

        }
        else if(cmd == "pmuda") {
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "rlista"){
            int param1, param2;
            in >> param1;
            in >> param2;

            if(param1 != 0 && param2 != 0) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "rrem") {
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "asoc"){
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "ades") {
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                cout << "Parametros validados com sucesso"<< endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando"<< endl;
            }
        }
        else if(cmd == "acom"){
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "psalva") {
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }
        }
        else if(cmd == "prepoe"){
            string param;

            if(!param.empty()) {
                cout << "Parametros validados com sucesso" << endl;
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando" << endl;
            }

        }
        else if(cmd == "plista") {

        }
        else if(cmd == "exec"){
            string param;
            in >> param;
            if(file_type(param)) {
                if(!file_reader(param, t)) {
                    cout << "Ficheiro nao existe!" << endl;
                }
            }
            else {
                cout << "Extensao do ficheiro nao e um ficheiro de texto (<NomeFicheiro>.txt)" << endl;
            }
        }
        else if(cmd == "sair") {
            exit(0);
        }
        else{
            cout << "Comando nao exist ! Inserir comando valido" << endl;
        }

    }
    else {
        cout << "Tamanho do mapa do simulador nao existe ... cria antes de efetuar qualquer outro comando (hnova <num linhas><num colunas>)"<< endl;
    }



}

void interface::start(bool flag, Terminal& t) {

    string line, cmd;

    /*if (flag)
        cmd_input();*/
    if(flag)
        create_visual(t);

    // getline(cin, line);

    // istringstream in(line); in >> cmd;

    //if (!in)
        //return;

    //cmd_validator(line);
}

void interface::cmd_input() {
    cout << error << endl;
    std::cout << "Comando: ";
}

void interface::set_map_state(bool active) {
    this->map = active;
}

bool interface::file_type(const string& file_name) {
    auto const pos = file_name.find_last_of('.');
    const auto type = file_name.substr(pos + 1);

    if(type == "txt") {
        return true;
    }
    return false;
}

void interface::create_visual_zonas(int x, int y, Terminal& t) {
    int pos_x_init = 5;
    int pos_y_init = 4;
    int id = 1;
    int total_zonas = habit->quant_zonas();
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(total_zonas != 0) {
                visual_zonas.push_back(new Window(pos_x_init, pos_y_init, 15, 4));
                t << move_to(pos_x_init+7, pos_y_init+1) << id;
                id++;
                pos_x_init = pos_x_init + 15;
                total_zonas--;
            }
        }
        pos_x_init = 5;
        pos_y_init = pos_y_init + 4;
    }
}



void interface::create_visual(Terminal& t) {
    if(get_map_state())
        create_visual_zonas(habit->get_linhas(),habit->get_colunas(), t);

    // Window w = Window(2, t.getNumRows()-2, 15, 4);
    std::string str_in;
    t << move_to(6, t.getNumRows()-1) << "Comando: ";
    t >> str_in;
    t.clear();
    cmd_validator(str_in, t);
}

bool interface::get_map_state() const {
    return map;
}

int interface::get_info_lines() const {
    return quant_info_lines;
}

void interface::set_info_lines() {
    quant_info_lines = quant_info_lines + 1;
}
