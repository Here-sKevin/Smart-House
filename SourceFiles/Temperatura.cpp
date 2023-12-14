
#include "../HeaderFiles/Temperatura.h"

temperatura::temperatura(string type) : propriedade(type), val_min(0) {}

temperatura::~temperatura() {}

void temperatura::ativa_efeito(string cmd, string aparelho) {
    if(cmd == "liga") {
        if(aparelho == "aquecedor") {
            //adiciona 1 grau por isntante

        }
        if(aparelho == "refrigerador") {
            //remove 1 grau a cada 3 isntante
        }
    }
}


