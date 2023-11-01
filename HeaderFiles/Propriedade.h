//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>
#include <map>

using namespace std;

class propriedade{
public:
     propriedade(string type);

private:
    map<string, int> id;
};

class temperatura : public propriedade {
public:
    temperatura(string type);
private:
    int val_min;
};

class luz : public propriedade {
public:
    luz(string type);

private:
    int val_min = 0;
};

class radiacao : public propriedade {
public:
    radiacao(string type);
private:
    int val_min = 0;
};

class vibracao : public propriedade {
public:
    vibracao(string type);
private:
    int val_min = 0;
};

class humidade : public propriedade {
public:
    humidade(string type);
private:
    int val_min = 0;
    int val_max = 100;
};

class fumo : public propriedade {
public:
    fumo(string type);
private:
    int val_min = 0;
    int val_max = 100;
};

class som : public propriedade {
public:
    som(string type);
private:
    int val_min = 0;
};

#endif //POO_2324_PROPRIEDADE_H
