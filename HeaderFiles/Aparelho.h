
#ifndef POO_2324_APARELHO_H
#define POO_2324_APARELHO_H
#include <string>
#include <map>
#include "Componente.h"

using namespace std;

class aparelho : componente{
public:
    aparelho(string type);
    ~aparelho();
    string get_id() const; // retorna id do aparelho
    int get_id_aparelho() const; //retorna valor do id static para ids dinamicos
    void set_id_aparelho() const; // define o id do proximo aparelho
    string get_type() const; // retona o tipo de aparelho
    virtual aparelho* clone() = 0; // retorna objeto com novo ponteiro
    int get_instance() const; // retorna a instancia atual interna
    void set_instance(); // define a instancia atual interna
    void reset_instance();
    bool get_isOn() const; // devolve o estado do aparelho atual
    void set_isOn(); // define o estado atual do aparelho
    virtual void set_val_change(string cmd) = 0; // operações responsaveis pelos aparelhos
    virtual void set_val_change_liga() = 0;
    virtual void set_val_change_desliga() = 0;

private:
    string id;
    static int id_aparelho;
    string type;
    int instance;
    bool isOn;
};

#endif //POO_2324_APARELHO_H
