#ifndef MOTOR_H
#define MOTOR_H

class Motor {
private:
    int pino1;
    int pino2;
    int frequencia_hz = 5000;
    int resolucao = 8;
    
public:
    Motor(int pino1, int pino2);
    void begin();
    void frente(int velocidade);
    void tras(int velocidade);
    void parar();
};

#endif
