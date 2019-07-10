---
title: INF1301 - Especificação de Requisitos
author:
- Brazão, Eduardo - 1810297
- Vasconcellos, Gabriel - 1810542
- Zimmer, Daniel - 1810589
institute: PUC-Rio 
date: 13 Abril, 2019
geometry: margin=3cm
indent: true
---

# Requisitos Funcionais

## Jogo

- O programa deve possibilitar o jogo de 2 a 4 jogadores em um tabuleiro de ludo.

- Cada jogador deve possuir 4 peças. Cada peça é representada por uma letra de A à D seguida de um número de 1 à 4. A letra representa o jogador e o número representa o número da peça.

- O objetivo é atingir a casa central do tabuleiro com todas suas peças. Deste modo, é necessário que o jogador de uma volta pelo tabuleiro até chegar na reta final, momento em que deve tirar um valor no dado equivalente ao número de casas da mesma, para que possa ser o vencedor. Caso tire um número maior, o jogador não poderá se movimentar.

- A cada turno o jogador deve lançar um dado de 6 faces e avançar com uma peça.

- As peças movem-se em sentido horário começando pela sua casa inicial até a sua casa final. Uma vez na casa final, a peça não pode mais realizar movimentos.

- Para o jogador sair de sua casa inicial para o caminho no tabuleiro, ele deve rolar um 6 no dado.

- Não é permitido mais do que um peça em cada casa. Caso uma peça venha a ocupar uma casa ocupada por um peão de outro jogador, o peão original será "comido" e regressará à casa inicial. Caso o peão original seja do mesmo jogador, a peça não poderá ser movimentada.

## Tabuleiro

- Casa Inicial: São os conjuntos de quatro casas, localizadas nos cantos do tabuleiro, para cada jogador.

- Caminho: Conjunto de 40 casas por onde as peças se movimentam no sentido horário, após sairem da casa inicial.

- Saída: São as casas que há junto a cada Casa Inicial.

- Reta final: São as 4 casas que se dirigem ao centro do tabuleiro até as casas finais. Cada jogador possui uma reta final.
 
- Casas Finais: São as casas que compões a reta final.

## Peças

- Todas as peças são iguais, apenas diferindo na letra e numero da peça. Cada jogador possui 4 peças.

# Requisitos Não-Funcionais

## Robustez

- Todos os dados de entrada serão validados pelo jogo.

- Caso uma entrada não seja válida, uma mensagem será exibida ao jogador e ele terá uma nova oportunidade para jogar a rodada.

## Corretude

- Todos os módulos devem ser testados individualmente, onde cada função é testada em diferentes circunstâncias.

## Reuso

- Os módulos serão implementados com a capacidade de reutiliza-los em mente.

## Manutenibilidade

- Todas as funções e módulos deverão ser desenvolvidos utilizando padrões de documentação
