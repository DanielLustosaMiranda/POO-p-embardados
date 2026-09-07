# Apresentação do PlatformIO:

1. Por que não usar a Arduino IDE? (Autocompletar, gestão de bibliotecas, integração com Git).

Como vocês já sabem, dentro da equipe de robótica Titans, nós trabalhamos com sitemas embarcados e robótica.
Para quem não é da equipe, na Titans nós trabalhamos com robótica.
Nós temos vários projetos e ao longo do tempo nós vamos trabalhando com vários hardwares diferentes.
Nós trabalhamos com ESP32, STM32 e também com arduino.
Então, o desenvolvimento que temos hoje, apesar de lidar com 3 placas diferentes ele ainda é bem begginer frindly em alguns projetos como o Very Small Size Socer (VSSS), os robos que os Traineers fizeram, os Balones e imagino que o Seguidor de linha usam o framwork do Arduino para programar.
  
No entanto, quando o projeto fica um pouco mais complexo e você precisa de multiplos arquivos `.cpp` e `.h` o uso do Arduino IDE se torna um pouco confuso, a gestão de bibliotecas também não é das melhores e a integração com Git deixa a desejar.
É nesse momento que entra em jogo o PlatformIO.
Ele é uma ferramenta que integra diversas funcionalidades em um so lugar, como IDE, gerenciador de bibliotecas, gerenciador de ambientes de desenvolvimento e por ai vai. Acho que a melhor funcinalidade que ele tem é de ser uma extensão no VScode que vocês já estão acostumados a usar. Existe uma versão Command Line interface que se integra com diversos editores de texto.

1. Por que não usar a Arduino IDE?

O Arduino IDE é uma ferramenta desenvolvida para ser simples e direta ao ponto. Para iniciantes que estão aprendendo a programar, essa simplicidade é uma grande vantagem.
No entanto, conforme o projeto cresce e se torna mais complexo, a Arduino IDE apresenta algumas limitações significativas. Por exemplo, quando precisamos organizar o código em múltiplos arquivos .cpp e .h, a IDE se torna confusa. Além disso, a gestão de bibliotecas não é tão eficiente quanto poderia ser, e a integração com sistemas de controle de versão como o Git é precária.
É aí que entra o PlatformIO.
O PlatformIO é uma ferramenta mais robusta que oferece diversas funcionalidades em um só lugar. Ele funciona como uma IDE completa, com recursos avançados de autocompletar código, gerenciamento de bibliotecas e integração com Git.
Além disso, o PlatformIO é compatível com diversos editores de texto, incluindo o VS Code, que muitos de vocês já estão acostumados a usar. Existem versões Command Line da ferramenta para quem prefere editores mais leves.


2. Estrutura de pastas do PlatformIO: src/, include/ (para arquivos .h) e lib/.

Antes de eu explicar essa parte eu preciso saber quantos de vocês já fizeram algum projeto em C quer precisava de mais de um arquivo e precisaram usar um .h ou .hpp para declarar funções e constantes. Quantos de vocês já viram isso alguma vez na vida se sim levantem a mão.

O que são esses .h e .c para aqueles que não conhecem. Bom esses arquivos que possuim .h no final contêm as definições de funções enquanto os arquivos .c ou .cpp contêm a implementação dessas funções. Segue exemplo abaixo:


```c
// mylib.h
#ifndef MYLIB_H

void printHello();
void printNum(int num);
int caulcularSoma(int a, int b);
double calcularMedia(double a, double b)

```

```c
// mylib.c
#include <stdio.h>

#include "mylib.h"

void printHello(){
    printf("Hello\n");
}

void printNum(int num){
    printf("Number: %d\n", num);
}

int calcularSoma(int a, int b){
    return a + b;
}

double calcularMedia(double a, double b){
    return (a + b) / 2;
}
```

O Motivo dessas ter dois aquivos assim está relacionado ao processo de compilação.
Na primeira fase um processo chamado pré-processamento é executado.
Nesse processo, o pré-processador lê o arquivo e substitui as diretivas de pré-processador por conteúdo. Por exemplo, #include "mylib.h" é substituído pelo conteúdo do arquivo "mylib.h".

E nisso a estrutura de pastas fica organizada dessa maneira:
src/ 
  main.c
lib/ 
  mylib.c
include/ 
  mylib.h

Assim fica separado as definições e as implementações deixando o código mais modular e na hora de compilar também facilita o entendimento.
Por enquanto isso é apenas um básico de linguagem C. Talvez seja um pouco novo, mas com o tempo vocês pegam o jeito.
Eu preciso que vocês tem esse conceito em mente pra agora que nós vamos avançar pra linguagem C++.

3. O arquivo platformio.ini (configuração do ESP32 e velocidade do monitor serial).

Sobre o processo de compilação, debugging e gerenciamento de bibliotecas, o coração que vai gerir isso é o arquivo platformio.ini.
É basicamente um arquivo de texto que define como o projeto deve ser compilado e quais bibliotecas devem ser usadas. No caso do ESP32, por exemplo, nós vamos definir a velocidade do monitor serial e qual a porta serial que devemos usar.

Segue aqui o exemplo de um arquivo platformio.ini com uma bliblioteca externa:
```ini
[env:esp32dev]
desk = ESP32 Dev Module
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
lib_deps = 
    khoih-prog/ESP32TimerInterrupt@^1.2.3
```

Agora explicando o que cada uma dessas coisas significa:

- Platform = Define qual é a arquitetura da placa que você vai usar. No caso é o ESP32.

- Board = Define qual é o modelo específico da placa que você vai usar. No caso é o ESP32 Dev Module.

- Framework = Define qual é o framework que você vai usar. No caso é o Arduino.

- Monitor_speed = Define a velocidade do monitor serial. No caso é 115200.

- Lib_deps = Define quais são as bibliotecas que você vai usar. No caso é o ESP32TimerInterrupt. Aqui você pode adicionar diversas blibliotecas que você vai usar no seu projeto.
