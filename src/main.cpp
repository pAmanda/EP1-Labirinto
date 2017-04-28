#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdio_ext.h>
#include"gameObject.hpp"
#include"player.hpp"
#include"drawn.hpp"
#include<time.h>
#include"trap.hpp"
#include"bonus.hpp"
#define LINE 22
#define COLUMN 50
#define QTDE 25
using namespace std;

//Inicializa funções da biblioteca ncurses.
void screen_init(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    refresh();
}

//Instacia objetos.
Drawn *drawn = new Drawn();
Player *player = new Player('@', 1, 1);
Map *map = new Map();
Trap *trap = new Trap();
Bonus *bonus = new Bonus();

//Coodenadas para o movimentos do player.
struct coordinate
{
  int x;
  int y;
};

//Tipos de movimntos do player.
const struct coordinate UP = { 0, -1 };
const struct coordinate DOWN = { 0, 1 };
const struct coordinate RIGHT = { 1, 0 };
const struct coordinate LEFT = { -1, 0 };

//Procedimento para fazer com que o player se movimente
void player_move(struct coordinate direction){
  if(map->getMaze(player->getPosy() + direction.y, player->getPosx() + direction.x) != '#' && map->getMaze(player->getPosy() + direction.y, player->getPosx() + direction.x) != '$' ){
    if(map->getMaze(player->getPosy() + direction.y, player->getPosx() + direction.x) == '-'){
      bonus->setScore(bonus->getScore()+1);
    }
    mvprintw(player->getPosy(), player->getPosx(), " ");
    map->setMaze(' ', player->getPosy(), player->getPosx());
    player->setPosx(player->getPosx() + direction.x);
    player->setPosy(player->getPosy() + direction.y);
    drawn->drawnPlayer(player);
  }
    move(0, 0);
}

//Printa na telaa as armadilhas
void printTrap(){
  srand(time(NULL));
  int tempx = rand()%(COLUMN);
  int tempy = rand()%(LINE);
  if(map->getMaze(tempy, tempx) == '-' || map->getMaze(tempy, tempx) == ' '){
      trap->setPosy(tempy);
      trap->setPosx(tempx);
      map->setMaze('%', trap->getPosy(), trap->getPosx());
      move(trap->getPosy(), trap->getPosx());
      addch(trap->getSprite());
  }
  refresh();
}

//Deleta objetos instaciados.
void end(){
  delete(map);
  delete(drawn);
  delete(player);
  delete(trap);
  delete(bonus);
}

//Detecta colisão do player com as armadilhas
void colision(struct coordinate direction){
  if(map->getMaze(player->getPosy() + direction.y, player->getPosx() + direction.x) == '%'){
    trap->setDamage(1);
    bonus->setScore(0);
  }
}

//Verifica se o player venceu
bool winner(){
  for(int l = 0; l < LINE; l++)
    for(int c = 0; c < COLUMN; c++){
      if(map->getMaze(l, c) == bonus->getSprite())
        return false;
    }
  if(map->getMaze(player->getPosy(), player->getPosy()) == '$' )
    return true;
  return false;
}

int main(){
  screen_init();
  curs_set(0); //Deixa o cursor invisível
  while(player->getAlive() || !player->getWinner()){
    drawn->drawnMap(map); //Desenha mapa
    drawn->drawnPlayer(player); //Desenha player
    refresh();
    int cont = 0;
    do{
      int c = wgetch(stdscr);
      cont++;
      switch(c){
        case KEY_UP:
          colision(UP);
          player_move(UP);
          break;
        case KEY_DOWN:
          colision(DOWN);
          player_move(DOWN);
          break;
        case KEY_LEFT:
          colision(LEFT);
          player_move(LEFT);
          break;
        case KEY_RIGHT:
          colision(RIGHT);
          player_move(RIGHT);
          break;
      }
      printTrap();
      mvprintw(23, 0, "Score: %d\tDamage: %d\n", bonus->getScore(), trap->getDamage());
      //Condição de derrota
      if(trap->getDamage() == 5){
        clear();
        mvprintw(LINE/2, COLUMN/2, "GAME OVER......GOODBYE");
        refresh();
        sleep(2);
        player->setAlive(false);
      }
      //Condição de vitória
      if(winner()){
        clear();
        mvprintw(LINE/2, COLUMN/2, "YOU WON......GOODBYE");
        refresh();
        sleep(2);
        player->setWinner(true);
      }
    }while(player->getAlive() || !player->getWinner());
  }
  void end();
  clrtoeol ();
  refresh ();
  endwin ();
  return 0;
}
