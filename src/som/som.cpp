#include "som.h"

Som::Som(int pin) {
    _pin = pin;
}

void Som::inicializar() {
    pinMode(_pin, INPUT);
}

void Som::lerNivelSom(int &valorSom) {
    valorSom = analogRead(_pin);
}