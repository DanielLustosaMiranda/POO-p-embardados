#include "Led.h"

#include <Arduino.h>
LED::LED(int pino) : pino(pino) {}

int LED::getPino(){
    return pino;
}

void LED::setPino(int pino){
    this->pino = pino; // O 'this->' é obrigatório aqui!
}

void LED::begin(){
    pinMode(pino, OUTPUT);
}

void LED::ligar(){
    digitalWrite(pino, HIGH);
}

void LED::desligar(){
    digitalWrite(pino, LOW);
}

void LED::alternar(){
    digitalWrite(pino, !digitalRead(pino));
}

void LED::acenderBrilhando(){
   for (int brilho = 1; brilho <= 255; brilho *= 2) {
    analogWrite(pino, brilho);
    delay(200);
   }
}
