//
// Created by KevinRodrigues on 10/28/2023.
//
#include "../HeaderFiles/Sensor.h"

sensor::sensor(int id, string cmd) {
    this->id = id;
    this->has_prop = cmd == "" ? false : true;
    this->prop = cmd;
    // propriedade prop(cmd);

    /*if(cmd == "temperatura") {
        //temperatura prop(cmd);
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

    }*/
}
