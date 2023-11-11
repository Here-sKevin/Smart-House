//
// Created by KevinRodrigues on 10/24/2023.
//

#ifndef POO_2324_INTERFACE_H
#define POO_2324_INTERFACE_H
#include <string>
#include "Habitacao.h"

using namespace std;

class interface {
public:
    interface(); // construtor por defeito
    ~interface(); // destrutor por defeito
    void menu(); // lista inical
    void config(); // estado da aplicacao
    void cmd_validator(const string& line); // execucao dos comandos inseridos pelo utilizador
    void start(bool flag); // inicia o simulador
    bool file_reader(const string& file_name); // leitura dos ficheiros e execução/leitura do conteudo
    void cmd_input(); // desenho para insecao de comandos
    void set_map_state(bool active); //estado de criação do mapa do simulador
    bool file_type(const string& file_name); // verificacao da extencao do ficheiro (helper)
private:
    string error;
    bool map = false;
    habitacao *habit;

};

#endif //POO_2324_INTERFACE_H
