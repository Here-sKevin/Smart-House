//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Sensor.h"

sensor::sensor(int id, string cmd) {
    this->id = id;
    this->has_prop = false;
    // propriedade prop(cmd);

    if(cmd == "temperatura") {
        temperatura t(cmd);
        prop= &t;
    }
    else if(cmd == "luz"){

    }
    else if(cmd == "radiacao"){

    }
    else if(cmd == "vibracao"){

    }
    else if(cmd == "humidade"){

    }
    else if(cmd == "fumo"){

    }
    else if(cmd == "som"){

    }
}
