#include<iostream>
#include "drawn.hpp"
#include "map.hpp"
#include "player.hpp"

using namespace std;

Drawn::Drawn(){}
Drawn::~Drawn(){}
void Drawn::drawnMap(Map *map){
  getch();
  map->chargeMaze();
  map->makeMaze();
}

void Drawn::drawnPlayer(Player *player){
  //map->setMaze(player->getSprite(), player->getPosy(), player->getPosx());
  move(player->getPosy(), player->getPosx());
  addch(player->getSprite());
}
