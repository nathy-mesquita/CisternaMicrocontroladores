
# Cisterna com arduino

>Projeto apresentado para composição de nota da disciplina de microcontroladores

[Link do projeto no Tinkercad](https://www.tinkercad.com/things/20tDjwq8P6S)

![Cisterna - Microcontroladores](https://user-images.githubusercontent.com/19518771/113497393-09047300-94da-11eb-9faa-4f034209d394.png)


### Itens do trabalho

A simbologia P&ID (Piping and Instrumentation Diagram/Drawing), ou seja, Diagrama
de Tubulações e Instrumentação, é muito utilizada em processos industriais. Alguns símbolos
são:

![figura1](https://user-images.githubusercontent.com/19518771/113497384-f9852a00-94d9-11eb-95b2-9ff2011ec407.png)


## Atividade Proposta

Desenvolver a aplicação com o Arduino, conforme ilustrado na Figura 2, que bombeia água de
uma cisterna.

![figura2](https://user-images.githubusercontent.com/19518771/113497377-df4b4c00-94d9-11eb-980b-209e8adc5dbd.png)

Sendo que a cisterna tem três sensores de nível, denominados N1, N2 e N3:

- N1 => 90% do nível máximo;
- N2 => 80% do nível máximo;
- N3 => 20% do nível máximo.

Além dos sensores, há uma válvula V e a bomba BB.

Utilizamos LEDs para indicar para a operação do processo industrial que os sensores, válvula e bomba foram acionados, ou seja, toda vez que um dos itens for acionado, um LED acionará.

### O processo de enchimento:

- Se N3, N2 e N1, não estiverem acionados, o tanque está vazio e a bomba deve
estar fechada e a válvula deverá ser aberta.
- Quando N3 for acionado, indicar para a operação que o nível chegou a 20%,
manter a bomba fechada e a válvula aberta;
- Quando N2 for acionado, indicar para a operação que o nível chegou a 80%,
manter a bomba fechada e a válvula aberta;
- Quando N1 for acionado, indicar para a operação que o nível chegou a 90%,
fechar a válvula e ligar a bomba;

### O processo de esvaziamento:

- Quando N1 for acionado, indicar para a operação que o nível está a 90%, manter a
válvula fechada e a bomba ligada;
- Quando N2 for acionado, indicar para a operação que o nível chegou a 80%, manter
a válvula fechada e a bomba ligada;
- Quando N3 for acionado, indicar para a operação que o nível chegou a 20%,
fechar a bomba e ligar a válvula.


### Lista de componentes

| Nome | Quantidade |
| ------ | ------ |
|Arduino Uno R3 |1 |
|Potenciometro|1 |
|LCD 16 x 2 |1 |
|Resistor 220|1 |
|Botão |2 |
|Resistor |7 |
|Led_N1_Vermelho |1 |
|Led_N2_Amarelo |1 |
|Led_N3_Verde|1 |
|Led_Bomba_Azul |1 |
|Led_Valvula_Branca |1 |

## Equipe 

- Anderson de Oliveira Apolinario -2017201232
- Camila Silveira Mendonça - 2017201332
- Carlos Igor de Lima Rezende de Carvalho - 2016200237
- Elaine Pereira Ludolpho de Lucas - 2016202485
- Maria Nathaly Gomes de Mesquita - 2016101511
- Ramon Feitosa Mesquita de Paiva - 2016103058
- Vivian Saldanha Campos - 2016202539