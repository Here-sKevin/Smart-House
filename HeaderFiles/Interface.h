

#ifndef POO_2324_INTERFACE_H
#define POO_2324_INTERFACE_H
#include <string>
#include <map>
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
    bool get_map_state() const; // verifica se existe limites de habitacao
    void set_map_state(bool active); //estado de criação do mapa do simulador
    bool file_type(const string& file_name); // verificacao da extencao do ficheiro (helper)
    void create_visual(Terminal& t); // desenha na console com recurso a bibioteca
    void create_visual_zonas(int x, int y, Terminal& t); // desenha as zonas na console com recurso a bibioteca

private:
    string error;
    bool map = false;
    habitacao *habit;
    vector <Window*> visual_zonas;
    vector<processador*> procSave;
    //std::map<string, processador*> ps;
};

#endif //POO_2324_INTERFACE_H
