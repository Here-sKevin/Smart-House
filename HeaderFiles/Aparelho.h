
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
    virtual bool check_prop_type(const string& cmd, const string& type) const = 0; //verifica se a propriedade em questão vai ser alterado conforme a possibilidade desse aparelho o alterar
    virtual int get_val(const string& cmd, const string& type) = 0; // retorna valor que vai ser incrementado/decrementado no valor da propriedade
    virtual aparelho* clone() = 0; // retorna objeto com novo ponteiro

private:
    int id;
    static int id_aparelho;
    string type;
};

#endif //POO_2324_APARELHO_H
