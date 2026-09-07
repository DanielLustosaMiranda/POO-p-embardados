#include "Robo.h"

#include <Arduino.h>

Robo::Robo(Motor esquerdo, Motor direito) : 
    motorEsquerdo(esquerdo), motorDireito(direito) {}

void Robo::begin() {
    motorEsquerdo.begin();
    motorDireito.begin();
}

void Robo::frente(int velocidade){
    motorEsquerdo.frente(velocidade);
    motorDireito.frente(velocidade);
}

void Robo::tras(int velocidade){
    motorEsquerdo.tras(velocidade);
    motorDireito.tras(velocidade);
}

void Robo::parar(){
    motorEsquerdo.parar();
    motorDireito.parar();
}

void Robo::virarParaDireita(int velocidade){
    motorEsquerdo.frente(velocidade);
    motorDireito.tras(velocidade);
}

void Robo::virarParaEsquerda(int velocidade){
    motorEsquerdo.tras(velocidade);
    motorDireito.frente(velocidade);
}

void Robo::rodopiarParaDireita(int velocidade){
    motorEsquerdo.frente(velocidade);
    motorDireito.tras(velocidade);
}

void Robo::rodopiarParaEsquerda(int velocidade){
    motorEsquerdo.tras(velocidade);
    motorDireito.frente(velocidade);
}

void Robo::rotinaDoQuadrado(){
    frente(128);
    delay(1000);
    parar();
    delay(1000);
    virarParaDireita(128);
    delay(1000);
    parar();
    delay(1000);
    frente(128);
    delay(1000);
    parar();
    delay(1000);
    virarParaDireita(128);
    delay(1000);
    parar();
    delay(1000);
}
