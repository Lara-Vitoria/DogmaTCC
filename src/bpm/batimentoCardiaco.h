#ifndef BPM_H
#define BPM_H

#include "Arduino.h" 

class BatimentoCardiaco {
public:
    BatimentoCardiaco(int pin);
    void inicializar();
    void lerBatimentoCardiaco(int &valorBpm);

private:
    int _pin;
};

#endif