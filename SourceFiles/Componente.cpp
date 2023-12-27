#include "../HeaderFiles/Componente.h"

int componente::genereted_id = 1;

int componente::generetedId() {
    return genereted_id++;
}
