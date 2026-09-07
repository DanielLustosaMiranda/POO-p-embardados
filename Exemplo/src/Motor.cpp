#include "Motor.h"

#include <Arduino.h>

Motor::Motor(int pino1, int pino2): 
    pino1(pino1), pino2(pino2) {}

void Motor::begin() {
    // Na nova versão (Arduino Core 3.x+), usamos apenas ledcAttach passando o pino físico.
    // O sistema gerencia os canais internamente para nós!
    ledcAttach(pino1, frequencia_hz, resolucao);
    ledcAttach(pino2, frequencia_hz, resolucao);
    
    parar(); // Começa com os motores parados
}

void Motor::frente(int velocidade){
    // Na nova versão, ledcWrite recebe o PINO, e não mais o CANAL
    ledcWrite(pino1, velocidade);
    ledcWrite(pino2, 0);
}

void Motor::tras(int velocidade){
    ledcWrite(pino1, 0);
    ledcWrite(pino2, velocidade);
}

void Motor::parar(){
    ledcWrite(pino1, 0);
    ledcWrite(pino2, 0);  
    Standings

 
}
