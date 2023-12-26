
#ifndef POO_2324_ASPERSOR_H
#define POO_2324_ASPERSOR_H

#include "../HeaderFiles/Aparelho.h"

class aspersor : public aparelho{
public:
    aspersor(string type);
    ~aspersor();
    bool check_prop_type(const string& cmd, const string& type) const override;
    int get_val(const string& cmd, const string& type) override;
    virtual aspersor* clone();

private:
    map<string, int> propsAlterLiga;
    map<string, int> propsAlterDesliga;
};

#endif //POO_2324_ASPERSOR_H
