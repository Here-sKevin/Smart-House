
#ifndef POO_2324_APARELHO_H
#define POO_2324_APARELHO_H
#include <string>
#include <map>

using namespace std;

class aparelho{
public:
    aparelho(string type);
    ~aparelho();
    int get_id() const;

    int get_id_aparelho() const;
    void set_id_aparelho() const;

    string get_type() const;

    virtual bool check_prop_type(const string& cmd, const string& type) const = 0;
    virtual int get_val(const string& cmd, const string& type) = 0;

    virtual aparelho* clone() = 0;


private:
    int id;
    static int id_aparelho;
    string type;
};

#endif //POO_2324_APARELHO_H
