# Objetivos
Ao transitar de projetos experimentais para sistemas embarcados complexos, a abordagem procedural clássica — com variáveis globais e funções amontoadas — rapidamente se torna insustentável. Esta capacitação foi desenhada para elevar o seu nível de desenvolvimento, conectando a abstração avançada de software ao controle físico de hardware de forma profissional, utilizando o poder do ESP32.

## O que é esperado que você compreenda até o fim do curso:

- A Filosofia da Orientação a Objetos (POO) no Hardware: Entender como representar componentes físicos reais (como motores e LEDs) como "Objetos" no código, dominando o encapsulamento para esconder as lógicas de pinos e configurações de hardware do arquivo principal.

- Arquitetura de Sistemas via Agregação: Compreender que sistemas complexos são montados a partir da união de partes menores independentes (Relação "Tem-um"). Você entenderá por que um "Robô" não deve acessar portas lógicas diretamente, mas sim delegar tarefas aos seus "Motores".

- Flexibilidade com Herança e Polimorfismo: Entender como projetar uma hierarquia de classes base e derivadas. Você vai compreender como diferentes componentes podem responder a um mesmo comando (como um método atualizar()) de maneiras totalmente diferentes em tempo de execução.

- O Paradigma Não-Bloqueante: Compreender definitivamente por que a função delay() é inimiga da robótica e como estruturar lógicas de tempo concorrentes baseadas em millis() integradas aos próprios objetos.

## O que você será capaz de fazer na prática com isso:

- Dominar o Ambiente PlatformIO: Configurar, compilar e gerenciar projetos no PlatformIO, separando corretamente declarações e implementações nas pastas include/ e src/, superando as limitações da Arduino IDE.

- Criar as Próprias Classes (.h e .cpp): Escrever arquivos de cabeçalho e de implementação do zero, criando módulos de código independentes e altamente reutilizáveis que você poderá levar para qualquer projeto futuro.

- Programar a Estrutura de um Robô Modular: Implementar a lógica real de um robô que controla dois motores e sistemas visuais, conectando todos esses objetos através de agregação.

- Limpar e Otimizar o Código Principal: Construir um loop de execução polimórfico onde o arquivo main.cpp torna-se extremamente legível e limpo — atuando apenas como um orquestrador de alto nível das classes que criamos, sem gerenciar pinos ou estados diretamente.