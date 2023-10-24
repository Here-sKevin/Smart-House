//
// Created by Kevin Rodrigues on 10/24/2023.
//

#ifndef POO_2324_INTERFACE_H
#define POO_2324_INTERFACE_H
#include <string>

using namespace std;

class interface {
public:
    interface();
    void menu();
    void config_game();
    void start_game(int state);
    void draw_cmd_input();
    //void exec_cmd(string line);
private:
    string error;
};

#endif //POO_2324_INTERFACE_H
