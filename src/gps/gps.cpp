#include "gps.h"


Gps::Gps(int rxPin, int txPin) :
  _rxPin(rxPin), _txPin(txPin) {}


void Gps::inicializar() {
  Serial2.begin(9600);
}

bool Gps::lerDadoGPS(float &latitude, float &longitude) {

  while (Serial2.available() > 0) { 
    if (_gps.encode(Serial2.read())) {

      if (_gps.location.isValid())  
      {
        latitude = _gps.location.lat();
        longitude = _gps.location.lng();

      } else {
        return false; 
      }

      delay(10000); 

      return true;
    }
  }

   return false;
}