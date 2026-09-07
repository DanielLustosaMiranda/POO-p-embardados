#ifndef LED_H
#define LED_H

class LED {
private:
  int pino;

public:
  LED(int pino);
  int getPino();
  void setPino(int pino);
  void begin();
  void ligar();
  void desligar();
  void alternar();
  void acenderBrilhando();
};

#endif
