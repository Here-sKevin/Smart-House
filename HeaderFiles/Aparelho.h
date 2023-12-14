
#ifndef POO_2324_APARELHO_H
#define POO_2324_APARELHO_H
#include <string>
using namespace std;

class aparelho{
public:
    aparelho(string cmd);
    ~aparelho();
    int get_id() const;

    int get_id_aparelho() const;
    void set_id_aparelho() const;

    virtual void set_cmd(string comando) = 0;


private:
    int id;
    string cmd;
    static int id_aparelho;
};

#endif //POO_2324_APARELHO_H
