
#ifndef POO_2324_AQUECEDOR_H
#define POO_2324_AQUECEDOR_H
#include "../HeaderFiles/Aparelho.h"

class aquecedor : public aparelho{
public:
    aquecedor(string type);
    ~aquecedor();
    bool check_prop_type(const string& cmd, const string& type) const override;
    int get_val(const string& cmd, const string& type) override;
    virtual aquecedor* clone();

private:
    map<string, int> propsAlterLiga;
    map<string, int> propsAlterDesliga;
};

#endif //POO_2324_AQUECEDOR_H
