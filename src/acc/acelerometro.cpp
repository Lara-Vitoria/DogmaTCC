#include "acelerometro.h"
#include <Wire.h>  

Acelerometro::Acelerometro(int sdaPin, int sclPin) :
  _sdaPin(sdaPin), _sclPin(sclPin) {}


void Acelerometro::inicializar() {
  Wire.begin(_sdaPin, _sclPin);

  while(!_accel.begin()){
    Serial.println("Acelerometro não detecctado");
    delay(2000);
  }

  Serial.println("Acelerometro detecctado");
}

void Acelerometro::lerDadoAcelerometro(float &x, float &y, float &z) {

  _accel.getEvent(&_event);                                      

  x = _event.acceleration.x;
  y = _event.acceleration.y;
  z = _event.acceleration.z;

}