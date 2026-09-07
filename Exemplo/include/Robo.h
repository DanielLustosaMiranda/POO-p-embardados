#ifndef ROBO_H
#define ROBO_H

#include "Motor.h"

class Robo {
private:
    Motor motorEsquerdo;
    Motor motorDireito;

public:
    Robo(Motor esquerdo, Motor direito);
    void begin();
    void frente(int velocidade);
    void tras(int velocidade);
    void parar();
    void virarParaDireita(int velocidade);
    void virarParaEsquerda(int velocidade);
    void rodopiarParaDireita(int velocidade);
    void rodopiarParaEsquerda(int velocidade);
    void rotinaDoQuadrado();
};

#endif
