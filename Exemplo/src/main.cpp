#include <Arduino.h>
#include "Led.h"
#include "Motor.h"
#include "Robo.h"

// Instancia um LED no pino 2 (LED onboard do ESP32 na maioria das placas)
LED ledStatus(2);

// Instancia os motores esquerdo e direito passando apenas os pinos
Motor motorEsquerdo(13, 12);
Motor motorDireito(14, 27);

// Instancia o Robô passando os objetos dos motores já criados
Robo meuRobo(motorEsquerdo, motorDireito);

void setup() {
    Serial.begin(115200);
    
    // Inicializa todos os componentes
    ledStatus.begin();
    meuRobo.begin();
    
    Serial.println("Robo iniciado e pronto!");
}

void loop() {
    // Pisca o LED para indicar que o loop está rodando
    ledStatus.alternar();
    
    // Executa a rotina do quadrado programada na classe Robo
    meuRobo.rotinaDoQuadrado();
}