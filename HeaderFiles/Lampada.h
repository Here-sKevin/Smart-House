
#ifndef POO_2324_LAMPADA_H
#define POO_2324_LAMPADA_H

#include "../HeaderFiles/Aparelho.h"

class lampada : public aparelho{
public:
    lampada(string type);
    ~lampada();

    bool check_prop_type(const string& cmd, const string& type) const override;
    int get_val(const string& cmd, const string& type) override;

    virtual lampada* clone();
private:
    map<string, int> propsAlterLiga;
    map<string, int> propsAlterDesliga;
};

#endif //POO_2324_LAMPADA_H
