#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdio_ext.h>
#include"gameObject.hpp"
#include"player.hpp"
#include"drawn.hpp"
#define LINE 22
#define COLUMN 50
using namespace std;

void screen_init(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    refresh();
}

Drawn *drawn = new Drawn();
Player *player = new Player('@', 1, 1);
Map *map = new Map();

struct coordinate
{
  int x;
  int y;
};

const struct coordinate UP = { 0, -1 };
const struct coordinate DOWN = { 0, 1 };
const struct coordinate RIGHT = { 1, 0 };
const struct coordinate LEFT = { -1, 0 };

void player_move(struct coordinate direction){
  if(map->getMaze(player->getPosy() + direction.y, player->getPosx() + direction.x) == '-'){
    mvprintw(player->getPosy(), player->getPosx(), " ");
    player->setPosx(player->getPosx() + direction.x);
    player->setPosy(player->getPosy() + direction.y);
    drawn->drawnPlayer(player);
  }
  move(0, 0);
}

int main(){
  screen_init();
  curs_set(0);
  while(TRUE){
    drawn->drawnMap(map);
    drawn->drawnPlayer(player);
    refresh();
    do{
      int c = wgetch(stdscr);

      switch(c){
        case KEY_UP:
          player_move(UP);
          break;
        case KEY_DOWN:
          player_move(DOWN);
          break;
        case KEY_LEFT:
          player_move(LEFT);
          break;
        case KEY_RIGHT:
          player_move(RIGHT);
          break;
      }

    }while(player->getAlive());
  }
  return 0;
}
