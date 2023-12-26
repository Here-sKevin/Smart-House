
#ifndef POO_2324_REFRIGERADOR_H
#define POO_2324_REFRIGERADOR_H

#include "../HeaderFiles/Aparelho.h"

class refrigerador : public aparelho{
public:
    refrigerador(string type);
    ~refrigerador();
    bool check_prop_type(const string& cmd, const string& type) const override;
    int get_val(const string& cmd, const string& type) override;
    refrigerador* clone() override;

private:
    map<string, int> propsAlterLiga;
    map<string, int> propsAlterDesliga;
};

#endif //POO_2324_REFRIGERADOR_H
