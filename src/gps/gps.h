#ifndef GPS_H
#define GPS_H

#include "Arduino.h"
#include <TinyGPSPlus.h>

class Gps {
public:
    Gps(int rxPin, int txPin);
    void inicializar();
    bool lerDadoGPS(float &latitude, float &longitude);

private:
    int _rxPin;
    int _txPin;
    TinyGPSPlus _gps;
};

#endif