# EP1-Labirinto

Primeiro trabalho prático da Disciplina Orientação a Objetos da UNB.

# Como funciona

Componentes:
- Player: '@'
- Parede: '#'
- Bôus: '-'
- Armadilha: '%'
- Final do labirinto: '$'

O Objetivo do jogo é chegar ao final do labirinto após ter pego todos os bônus e com o "damage" inferior a 5. Ao passar por uma armadilha(damage), a mesma é destruída e o score do jogador é zerado. O score aumenta à media que o player pega os bônus. O player não é capaz de atravessar as paredes.

- Condição de derrota:
Se o player obter o valor do "damage" superior a 4, perde o jogo.

- Condição de vitória:
Se o player obter todos os bônus e chegar ao final do labirinto com o valor do "damage" inferior a 5, ganha o jogo.

- Pontuação:
A medida que o player pega os bônus, seu score aumenta. Se o player passar por uma armadilha, ela é destruída, no entanto o score é zerado.

# Como compilar e executar o projeto

1- Clone o código para sua máquina.
2- No terminal do linux, abra a pasta do projeto.
3- Para compilar, use o comando "make" no terminal.
4- Para executar, use o comando "make run" no terminal.
5- Para limpar a pasta bin/ e obj/, use o comando "make clean" no terminal.
