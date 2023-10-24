//
// Created by KevinRodrigues on 10/24/2023.
//

#include "Interface.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

interface::interface() {
    //criar habitação
}

void interface::menu(){
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|                                                      Simulador Habitacao                                               |" << endl;
    cout << "|                                                      1 -> Jogar                                                      |" << endl;
    cout << "|                                                      2 -> Sair                                                       |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    int option;
    cout << endl;
    cout << endl;
    cout << "Opcao: ";
    cin >> option;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cin >> option;
    }

    switch (option) {
        case 1:
            cout << "Jogo inicializado!" << endl;
            config_game();
            break;
        case 2:
            return;

        default:
            cout << "Opcao invalida \n";
            break;
    }

}

void interface::config_game() {
    bool state=false;

    while(!state){
        start_game(state);
        state=true;
    }
}

void interface::start_game(int state) {
    string line, cmd;

    if(state){
        draw_cmd_input();
    }
    getline(cin, line);

    istringstream in(line);
    in >> cmd;

    if(!in){
        return;
    }

   // exec_cmd(line);
}

void interface::draw_cmd_input() {
    cout << endl;
    cout << endl;
    cout << error << endl;

    for (int i = 0; i < 120; i++) {
        cout << "-";
    }
    cout << endl;
    cout << endl;
    cout << "Comando: ";
}