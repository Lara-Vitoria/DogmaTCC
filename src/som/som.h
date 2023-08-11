#ifndef SOM_H
#define SOM_H

#include "Arduino.h"

class Som {
public:
    Som(int pin);
    void inicializar();
    void lerNivelSom(int &valorSom);

private:
    int _pin; 
};

#endif