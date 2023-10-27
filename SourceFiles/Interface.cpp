//
// Created by KevinRodrigues on 10/24/2023.
//

#include "../HeaderFiles/Interface.h"
#include <iostream>
#include <sstream>
#include <fstream>


interface::interface() {

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

void interface::config() {
    string line, cmd;
    bool flag = false;
    while (true) {
        start(flag);
        flag = true;
    }

}

bool interface::file_reader(const string& file_name) {
    ifstream data(file_name);
    string line;

    if (!data.is_open()) {
        return false;
    }

    while (!data.eof()) {
        getline(data, line);
        istringstream in(line);
        string cmd; in >> cmd;
        cmd_validator(line);
    }
    data.close();
    return true;
}

void interface::cmd_validator(const string& line) {

    if (line.empty())
        return;

    istringstream in(line);
    string cmd;

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
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
            set_map_state(true);
        }
        else if(cmd == "hrem") {

        }
        else if(cmd == "znova"){

            int paraml, paramc;
            in >> paraml;
            in >> paramc;

            if(paraml != 0 && paramc != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zrem") {
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zlista"){

        }
        else if(cmd == "zcomp") {
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zprops"){
            int param;
            in >> param;

            if(param != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "pmod") {
            int param1,param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && param3 != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }

        }
        else if(cmd == "cnovo"){
            int param1;
            char param2;
            string param3;

            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "crem") {
            int param1, param3;
            char param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                cout << "Parametros validados com sucesso";
            }
            else{
                cout << "Parametros nao corresponder ao tipo de comando";
            }

        }
        else if(cmd == ""){

        }
        else if(cmd == "") {

        }
        else if(cmd == ""){

        }
        else if(cmd == "") {

        }
        else if(cmd == ""){

        }
        else if(cmd == "") {

        }
        else if(cmd == ""){

        }
        else if(cmd == "") {

        }
        else if(cmd == ""){

        }
        else if(cmd == "") {

        }
        else if(cmd == "exec"){
            string param;
            in >> param;
            if(file_type(param)) {
                if(!file_reader(param)) {
                    cout << "Ficheiro nao existe!";
                }
            }
            else {
                cout << "Extensao do ficheiro nao e um ficheiro de texto (<NomeFicheiro>.txt)";
            }
        }
        else if(cmd == "sair") {
            exit(0);
        }
        else{
            cout << "Comando nao exist ! Inserir comando valido";
        }

    }
    else {
        cout << "Tamanho do mapa do simulador não existe ... cria antes de efetuar qualquer outro comando (hnova <num linhas><num colunas>)";
    }



}

void interface::start(bool flag) {

    string line, cmd;
    if (flag)
        cmd_input();

    getline(cin, line);

    istringstream in(line); in >> cmd;

    if (!in)
        return;

    cmd_validator(line);
}

void interface::cmd_input() {
    cout << error << endl;
    cout << "Comando: ";
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
