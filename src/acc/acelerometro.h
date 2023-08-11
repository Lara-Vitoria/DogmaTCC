#ifndef ACC_H
#define ACC_H

#include "Arduino.h"
#include <Adafruit_Sensor.h>                                    // Importa a biblioteca Adafruit_Sensor
#include <Adafruit_ADXL345_U.h>                                 // Importa a biblioteca Adafruit_ADXL345_U

class Acelerometro {
public:
    Acelerometro(int _sdaPin, int _sclPin);
    void inicializar();
    void lerDadoAcelerometro(float &x, float &y, float &z);

private:
    int _sdaPin;
    int _sclPin;
    sensors_event_t _event;
    Adafruit_ADXL345_Unified _accel = Adafruit_ADXL345_Unified();
};

#endif