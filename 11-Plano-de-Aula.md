Estrutura do Treinamento (Aprox. 3h30 - 4h)
### Módulo 1: Setup Profissional e o "Hello World" Orientado a Objetos (45 min)
Objetivo: Tirar o aluno do Arduino IDE e introduzir a mentalidade de arquivos separados (POO).

- Apresentação do PlatformIO:

    - Por que não usar a Arduino IDE? (Autocompletar, gestão de bibliotecas, integração com Git).

    - Estrutura de pastas do PlatformIO: src/, include/ (para arquivos .h) e lib/.

    - O arquivo platformio.ini (configuração do ESP32 e velocidade do monitor serial).

### Módulo 1: Classes, Objetos e Encapsulamento

- Prática: Criar a classe Led.

- Como ensinar: Mostre como o código procedural espalha pinMode e digitalWrite. Em seguida, crie um Led.h e Led.cpp.

- Código-chave: A classe terá um construtor que recebe o pino e já faz o pinMode. Terá métodos públicos como ligar(), desligar() e alternar() (toggle). O número do pino deve ser um atributo private.

- Dica didática: Mostre como instanciar dois LEDs diferentes no main.cpp torna o código instantaneamente mais legível.

### Módulo 2: O Robô e o conceito de Agregação (1 hora)
- Objetivo: Mostrar como objetos menores constroem um sistema complexo.

    - Criando a Classe Motor:

    - Atributos: Pinos de direção e pino de PWM (velocidade).

    - Métodos: frente(velocidade), tras(velocidade), parar().

- Conceito 2: Agregação:

    - A Prática: Criar a classe Robo.

    - Como ensinar: Explique que um robô tem motores. A agregação é exatamente essa relação de "tem um" (HAS-A).

    - A classe Robo vai instanciar dois objetos da classe Motor (ex: motorEsquerdo e motorDireito) como seus atributos privados.

    - Crie métodos de alto nível na classe Robo, como andarFrente(), virarEsquerda(). Internamente, o método virarEsquerda() do Robô vai chamar motorEsquerdo.tras() e motorDireito.frente().

    - Dica didática: Aqui os alunos terão um momento "Aha!". Eles vão perceber que o desenvolvedor que usa a classe Robo no main.cpp não precisa saber quais pinos controlam os motores, abstraindo a complexidade de hardware.

#### Módulo 3: Herança, Polimorfismo e Sistemas Não-Bloqueantes (1 hora e 15 min)

- Objetivo: Introduzir conceitos avançados de POO para resolver o problema clássico do uso de delay() no Arduino.

    - O Problema: Como fazer um LED piscar de forma independente enquanto o robô anda, sem que um delay(500) trave os motores?

    - Conceito 3: Herança:

    - A Prática: Criar uma classe base chamada ComponenteVisual.

    - Crie as classes filhas LedSimples e LedPiscante que herdam da classe base.

    - O LedPiscante terá um atributo de intervalo e usará o millis() do ESP32 para saber a hora de mudar de estado, sem travar o processador.

- Conceito 4: Polimorfismo:

    - A Prática: Atualizar todos os componentes do robô com um único comando.

    - Na classe base, crie um método virtual puro: virtual void atualizar() = 0;.

    - Cada classe filha implementa o seu próprio atualizar(). Para o LedSimples, não faz nada (ou mantém aceso). Para o LedPiscante, verifica o millis() e pisca.

    - No main.cpp (ou dentro da própria classe Robo), crie um Array de Ponteiros para ComponenteVisual.

    - Dica didática: Mostre a elegância de um loop for que percorre a lista de componentes chamando componentes[i]->atualizar();. O sistema descobre sozinho em tempo de execução qual comportamento deve executar. Isso é o polimorfismo na veia!

### Módulo 4: O "Grand Finale" (45 min)
- Objetivo: Consolidar o conhecimento escrevendo o main.cpp mais limpo que os alunos já viram.


    - A Prática: A integração final.

    - O arquivo main.cpp deve ficar parecido apenas com isso:
```C++
#include "Robo.h"

Robo meuRobo;void setup() {
    meuRobo.inicializar(); // Configura todos os pinos internamente
    meuRobo.ligarFarois();
}void loop() {
    meuRobo.atualizarSistemas(); // O polimorfismo cuidando dos LEDs piscantes e sensores usando millis()
    meuRobo.fazerRotinaQuadrado(); // Lógica de movimento
}
```
- Desafio Prático: Peça para os alunos alterarem a classe filha de LED para criar um LedFade (que faz o brilho pulsar suavemente via PWM usando canais LEDC do ESP32) e peça para adicionarem ao array polimórfico do robô. Se o design foi bem feito, eles não precisarão alterar o main.cpp.

### Módulo 5: Injeção de Dependências e Princípios SOLID (1 hora)
- Objetivo: Mostrar como construir um código altamente modular, fácil de modificar e testar (foco no 'D' de Inversão de Dependência do SOLID).

    - O Problema: Atualmente, a classe Robo instancia os motores diretamente em seu interior. Se amanhã decidirmos trocar o shield de motores L298N por um driver Ponte H diferente, teríamos que alterar o código principal do Robô.
    
    - Conceito 5: Injeção de Dependência e Interfaces:
    
    - A Prática: Criar uma interface (uma classe base abstrata) chamada IMotor, com métodos puramente virtuais como frente() e parar().
    
    - Em vez da classe Robo criar os motores internamente, o construtor do Robo passa a receber os ponteiros para os motores como parâmetro: Robo(IMotor* esquerdo, IMotor* direito).
    
    - Dica didática: Esse é um momento "Mente Explodindo". Explique aos alunos que o robô agora não sabe mais qual hardware está rodando! Isso permite injetar um "MotorSimulado" (Mock) para testar a lógica do robô no computador sem nem precisar de placa ou ESP32.

### Módulo 6: Máquinas de Estado Orientadas a Objetos (State Pattern) (1 hora)
- Objetivo: Substituir a clássica "sopa de if/else" no Arduino por um sistema de comportamentos limpo e expansível.

    - O Problema: O robô está ganhando sensores (ultrassônico, segue-linha). A lógica central está ficando lotada de condicionais cruzadas para decidir se o robô deve andar, desviar ou parar.
    
    - Conceito 6: Padrão de Projeto "State" (Estado):
    
    - A Prática: Criar uma classe base chamada EstadoRobo com um método virtual puro executar(Robo* robo).
    
    - Criar classes filhas para cada comportamento: EstadoBuscando, EstadoDesviando e EstadoParado.
    
    - A classe Robo passa a ter um ponteiro para o Estado atual. A cada ciclo de loop, o Robô apenas chama estadoAtual->executar(this);. O próprio Estado decide a hora de mandar o Robô transitar para o próximo estado.
    
    - Dica didática: Mostre como adicionar um comportamento novo (ex: "Dança da Vitória") agora significa apenas criar uma nova classe `EstadoDanca`, sem alterar nenhuma linha de código da lógica existente. Isso prova aos alunos o valor prático de usar padrões de projeto no embarcado.

### Dicas de Ouro para a Condução
- Evite a síndrome do quadro em branco: Não faça os alunos digitarem tudo do zero. Forneça um repositório no GitHub com o esqueleto (os .h com as assinaturas já prontas) e foque a aula na implementação (.cpp) e na lógica dos conceitos.

- C++ Moderno no Embarcado: Lembre aos alunos que o ESP32 tem muita memória em comparação a um Arduino Uno. O overhead de funções virtuais (polimorfismo) é insignificante aqui, mas o ganho em organização de arquitetura de software é massivo.
