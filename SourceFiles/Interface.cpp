
#include "../HeaderFiles/Interface.h"
#include "../HeaderFiles/Processador.h"
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

    delete habit;
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
    bool flag = true;
    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    print_size(t);
    while(flag) {
        flag = start(flag, t);
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

bool interface::cmd_validator(const string& line, Terminal& t) {
    if (line.empty())
        return true;

    istringstream in(line);
    string cmd;

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
                t << move_to(1, 1) << "Parametros validados com sucesso\n";

                if((paraml >= 2 && paraml <= 4) && (paramc >= 2 && paramc <= 4)){
                    if(!get_map_state()) {
                        habit = new habitacao(paraml,paramc);
                        set_map_state(true);
                    }
                    else{
                        t << move_to(1, 1) << "Habitacao ja criada\n";
                    }
                }
                else {
                    t <<move_to(1, 1) << "A habitacao devera ter um tamanho minimo de 2x2 e maximo de 4x4\n";
                }
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "hrem") {
            delete habit;
            set_map_state(false);
            t << move_to(1, 1) << "Habitacao eliminada!\n";
        }
        else if(cmd == "znova"){

            int paraml, paramc;
            in >> paraml;
            in >> paramc;

            if(paraml != 0 && paramc != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->create_zona(paraml, paramc);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "zrem") {
            int param;
            in >> param;

            if(param != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->delete_zona(param);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
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
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
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
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "pmod") {
            int param1,param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->set_prop(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
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
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->cria_comp(param1, param2, param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "crem") {
            int param1;
            string param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty()  && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->delete_comp(param1,param2,param3);

            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "rnova"){
            int param1, param5, param6;
            string param2,param3,param4;
            in >> param1;
            in >> param2;
            in >> param3;
            in >> param4;
            in >> param5;
            in >> param6;

            if(param1 != 0 && !param2.empty() && !param3.empty() && !param4.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->cria_regra(param1,param2,param3,param4, param5,param6);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }

        }
        else if(cmd == "pmuda") {
            int param1;
            string param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->change_proc_cmd(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "rlista"){
            int param1;
            string param2;
            in >> param1;
            in >> param2;

            if(param1 != 0 && !param2.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->getAsStringRegras(param1,param2);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "rrem") {
            int param1, param3;
            string param2;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && param3 != 0) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->delete_regra(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "asoc"){
            int param1;
            string param2, param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->set_id_aparelho_proc(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "ades") {
            int param1;
            string param2,param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->remove_id_aparelho_proc(param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "acom"){
            int param1;
            string param2,param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                t << habit->send_cmd(cmd,param1,param2,param3);
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "psalva") {
            int param1;
            string param2,param3;
            in >> param1;
            in >> param2;
            in >> param3;

            if(param1 != 0 && !param2.empty() && !param3.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                ps.insert(pair<string,processador*>(param3,habit->duplica(param1,param2)));
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }
        }
        else if(cmd == "prepoe"){
            string param;
            in >> param;

            if(!param.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                for (auto itr = ps.begin(); itr != ps.end(); itr++) {
                    if(param == itr->first){
                        habit->set_proc_saved(*itr->second);
                    }
                }
            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }

        }
        else if(cmd == "prem"){
            string param;
            in >> param;

            if(!param.empty()) {
                t << move_to(1, 1) << "Parametros validados com sucesso\n";
                bool found = false;
                for (auto itr = ps.begin(); itr != ps.end(); itr++) {
                    if(param == itr->first){
                        found=true;
                    }
                }
                if(found){
                    ps.erase(param);
                    t << "Processador em memoria foi eliminado \n";
                }


            }
            else{
                t << move_to(1, 1) << "Parametros nao corresponder ao tipo de comando\n";
            }

        }
        else if(cmd == "plista") {
            std::ostringstream os;
            os << "Procesadores gravados em memoria \n";

            for (auto itr = ps.begin(); itr != ps.end(); itr++) {
                os << "Nome: " << itr->first << " Id: " << itr->second->get_id() << " ZonaId: " << itr->second->get_zona_asoc() << "\n";
            }

            t << os.str();
        }
        else if(cmd == "exec"){
            string param;
            in >> param;
            if(file_type(param)) {
                if(!file_reader(param, t)) {
                    t << move_to(1, 1) << "Ficheiro nao existe!\n";
                }
            }
            else {
                t << move_to(1, 1) << "Extensao do ficheiro nao e um ficheiro de texto (<NomeFicheiro>.txt) \n";
            }
        }
        else if(cmd == "sair") {
            return false;
        }
        else{
            t << move_to(1, 1) << "Comando nao existe ! Inserir comando valido\n";
        }

    }
    else {
        t << move_to(1, 1) << "Tamanho do mapa do simulador nao existe!\n Cria antes de efetuar qualquer outro comando \n(hnova <num linhas><num colunas>)";

    }
    return true;
}

bool interface::start(bool flag, Terminal& t) {
    if(flag){
        flag = create_visual(t);
        return flag;
    }
    return flag;
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



bool interface::create_visual(Terminal& t) {

    if(get_map_state())
        create_visual_zonas(habit->get_linhas(),habit->get_colunas(), t);

    std::string str_in;
    t << move_to(6, t.getNumRows()-4) << "Comando: ";
    t >> str_in;
    t.clear();
    bool res = cmd_validator(str_in, t);
    return res;

}

bool interface::get_map_state() const {
    return map;
}


