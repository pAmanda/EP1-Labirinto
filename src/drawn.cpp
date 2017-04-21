#include<iostream>
#include <unistd.h>
#include <ncurses.h>
#include "drawn.hpp"
#include "map.hpp"
#include "player.hpp"

using namespace std;

Drawn::Drawn(){}
Drawn::~Drawn(){}
void Drawn::drawnMap(){
  Map *map = new Map();
  Player *player = new Player('@', 1, 1);
  getch();
  map-> chargeMaze();
  map->setMaze(player->getSprite(), player->getPosy(), player->getPosx());
  map->makeMaze();
}
