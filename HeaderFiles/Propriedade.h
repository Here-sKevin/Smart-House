//
// Created by KevinRodrigues on 10/28/2023.
//

#ifndef POO_2324_PROPRIEDADE_H
#define POO_2324_PROPRIEDADE_H
#include <string>

using namespace std;

class propriedade{
public:


private:
    // auto key[2];
};

class temperatura : public propriedade {
public:

private:
    int val_min = -273;
};

class luz : public propriedade {
public:

private:
    int val_min = 0;
};

class radiacao : public propriedade {
public:

private:
    int val_min = 0;
};

class vibracao : public propriedade {
public:

private:
    int val_min = 0;
};

class humidade : public propriedade {
public:

private:
    int val_min = 0;
    int val_max = 100;
};

class fumo : public propriedade {
public:

private:
    int val_min = 0;
    int val_max = 100;
};

class som : public propriedade {
public:

private:
    int val_min = 0;
};

#endif //POO_2324_PROPRIEDADE_H
