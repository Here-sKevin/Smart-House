//
// Created by KevinRodrigues on 10/24/2023.
//

#ifndef POO_2324_INTERFACE_H
#define POO_2324_INTERFACE_H
#include <string>
#include "Habitacao.h"
#include "../library/Terminal.h"

using namespace std;
using namespace term;

class interface {
public:
    interface(); // construtor por defeito
    ~interface(); // destrutor por defeito
    void menu(); // lista inical
    void config(); // estado da aplicacao
    void cmd_validator(const string& line, Terminal& t); // execucao dos comandos inseridos pelo utilizador
    void start(bool flag, Terminal& t); // inicia o simulador
    bool file_reader(const string& file_name, Terminal& t); // leitura dos ficheiros e execução/leitura do conteudo
    void cmd_input(); // desenho para insecao de comandos
    bool get_map_state() const;
    void set_map_state(bool active); //estado de criação do mapa do simulador
    bool file_type(const string& file_name); // verificacao da extencao do ficheiro (helper)
    void create_visual(Terminal& t);
    void create_visual_zonas(int x, int y, Terminal& t);
    int get_info_lines() const;
    void set_info_lines();

private:
    string error;
    bool map = false;
    habitacao *habit;
    vector <Window*> visual_zonas;
    int quant_info_lines = 0;

};

#endif //POO_2324_INTERFACE_H
