
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

interface::interface() {}

interface::~interface() {
    for(auto & visual_zona : visual_zonas) {
        delete visual_zona;
    }
    visual_zonas.clear();

    for(auto & save : procSave) {
        delete save;
    }
    procSave.clear();
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

    // Window wmsg = Window(0, 0, 50, 24);
    // Window wzonas = Window(81, 1, 39, 24);
    //Window wcmd = Window(1, 25, 119, 4);


    print_size(t);
    while(true) {
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
    //t.clear();

    in >> cmd;
    if(map || cmd == "hnova" || cmd == "exec" || cmd == "sair") {
        if(cmd == "prox") {
            habit->exec_action();
        }
        else if(cmd == "avanca") {
            int param;
            in >> param;
            for(int i=0; i < param; i++){
                habit->exec_action();
            }
        }
        else if(cmd == "hnova"){
            int paraml, paramc;
            in >> paraml;
            in >> paramc;
            if(paraml != 0 && paramc != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";

                if((paraml >= 2 && paraml <= 4) && (paramc >= 2 && paramc <= 4)){
                    if(!get_map_state()) {
                        habit = new habitacao(paraml,paramc);
                        set_map_state(true);
                        habit->draw_map(paraml, paramc);
                    }
                    else{
                        t << move_to(1, 1) << "Habitacao ja criada";
                    }
                }
                else {
                    t <<move_to(1, 1) << "A habitacao devera ter um tamanho minimo de 2x2 e maximo de 4x4";
                }
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "hrem") {
            delete habit;
            set_map_state(false);
            t << move_to(1, 1) << "Habitacao eliminada!";
        }
        else if(cmd == "znova"){

            int paraml, paramc;
            in >> paraml;
            in >> paramc;

            if(paraml != 0 && paramc != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->create_zona(paraml, paramc, t);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zrem") {
            int param;
            in >> param;

            if(param != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->delete_zona(param);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zlista"){
            t << move_to(1, 1) << habit->to_string();
        }
        else if(cmd == "zcomp") {
            int param;
            in >> param;

            if(param != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                habit->set_srczona(param);
                t << habit->getAsStringComp();
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "zprops"){
            int param;
            in >> param;

            if(param != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                habit->set_srczona(param);
                t << habit->getAsStringProps();
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "pmod") {
            int param1,param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->set_prop(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
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
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->cria_comp(param1, param2, param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "crem") {
            int param1, param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty()  && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->delete_comp(param1,param2,param3);

            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "rnova"){
            int param1, param2, param4, param5, param6;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;
            in >> param4;
            in >> param5;
            in >> param6;

            if(param1 != 0 && param2 != 0 && !param3.empty() && param4 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->cria_regra(param1,param2,param3,param4, param5,param6);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }

        }
        else if(cmd == "pmuda") {
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->change_proc_cmd(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "rlista"){
            int param1, param2;
            in >> param1;
            in >> param2;

            if(param1 != 0 && param2 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                t << habit->getAsStringRegras(param1,param2);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "rrem") {
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->delete_regra(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "asoc"){
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->set_id_aparelho_proc(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "ades") {
            int param1, param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->remove_id_aparelho_proc(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "acom"){
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                habit->send_cmd(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "psalva") {
            int param1, param2;
            string param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && param2 != 0 && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                procSave.push_back(habit->duplica(param1,param2, param3));
               // ps.insert(pair<string,int>(param3,habit->duplica(param1,param2,param3)));
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }
        }
        else if(cmd == "prepoe"){
            string param;
            in >> param;

            if(!param.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                for(auto & save : procSave) {
                    if(param == save->get_nome_saved()) {
                        habit->set_proc_saved(*save);
                    }
                }
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }

        }
        else if(cmd == "prem"){
            string param;
            in >> param;

            if(!param.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso";
                int i=-1, index=-1;
                for(auto & save : procSave) {
                    i++;
                    if(param == save->get_nome_saved()) {
                       index=i;
                    }
                }
                if(index>-1) {
                    delete procSave[index];
                    procSave.erase(procSave.begin() + i);
                }
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando";
            }

        }
        else if(cmd == "plista") {
            std::ostringstream os;
            os << "Procesadores gravados em memoria \n";
            for(auto & save : procSave) {
                os << "Nome: " << save->get_nome_saved() << " Id: " << save->get_id() << " ZonaId: " << save->get_zona_asoc() << "\n";
            }
            t << os.str();
        }
        else if(cmd == "exec"){
            string param;
            in >> param;
            if(file_type(param)) {
                if(!file_reader(param, t)) {
                    t << move_to(1, 1) << "Ficheiro nao existe!";
                }
            }
            else {
                t << move_to(1, 1) << "Extensao do ficheiro nao e um ficheiro de texto (<NomeFicheiro>.txt) ";
            }
        }
        else if(cmd == "sair") {
            exit(0);
        }
        else{
            t << move_to(1, 1) << "Comando nao existe ! Inserir comando valido";
        }

    }
    else {
        t << move_to(1, 1) << "Tamanho do mapa do simulador nao existe!\n Cria antes de efetuar qualquer outro comando \n(hnova <num linhas><num colunas>)";

    }
}

void interface::start(bool flag, Terminal& t) {
    if(flag)
        create_visual(t);
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
    int pos_x_init = 55;
    int pos_y_init = 4;
    int total_zonas = habit->quant_zonas();

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            if(total_zonas != 0) {
                if(habit->can_draw_inGrid(i,j)) {
                    visual_zonas.push_back(new Window(pos_x_init, pos_y_init, 15, 4));
                    t << move_to(pos_x_init+7, pos_y_init+1) << habit->get_zona_id(i,j);
                }
                pos_x_init = pos_x_init + 15;
            }
        }
        pos_x_init = 55;
        pos_y_init = pos_y_init + 4;
    }
}



void interface::create_visual(Terminal& t) {
    // Window wmsg = Window(0, 0, 50, 24);
    // Window wzonas = Window(81, 1, 39, 24);
    // Window wcmd = Window(1, 25, 119, 4);

    if(get_map_state())
        create_visual_zonas(habit->get_linhas(),habit->get_colunas(), t);


    std::string str_in;
    t << move_to(6, t.getNumRows()-4) << "Comando: ";
    t >> str_in;
    t.clear();
    cmd_validator(str_in, t);

    //new Window(1, 1, 20, 20);
    //new Window(1, 1, 20, 20);

}

bool interface::get_map_state() const {
    return map;
}


