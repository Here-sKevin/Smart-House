
#ifndef POO_2324_APARELHO_H
#define POO_2324_APARELHO_H
#include <string>
#include <map>

using namespace std;

class aparelho{
public:
    aparelho(string type);
    ~aparelho();
    int get_id() const; // retorna id do aparelho
    int get_id_aparelho() const; //retorna valor do id static para ids dinamicos
    void set_id_aparelho() const; // define o id do proximo aparelho
    string get_type() const; // retona o tipo de aparelho
    virtual aparelho* clone() = 0; // retorna objeto com novo ponteiro
    int get_instance() const;
    void set_instance();
    bool get_isOn() const;
    void set_isOn();
    virtual void set_val_change(string cmd) = 0;

private:
    int id;
    static int id_aparelho;
    string type;
    int instance;
    bool isOn;
};

#endif //POO_2324_APARELHO_H
