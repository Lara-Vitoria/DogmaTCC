#include "batimentoCardiaco.h"

BatimentoCardiaco::BatimentoCardiaco(int pin) {
  _pin = pin;
}

void BatimentoCardiaco::inicializar() {
  pinMode(_pin, INPUT);
}

void BatimentoCardiaco::lerBatimentoCardiaco(int &valorBpm) {
  valorBpm = analogRead(_pin);
}