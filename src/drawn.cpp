#include<iostream>
#include "drawn.hpp"
#include "map.hpp"
#include "player.hpp"

using namespace std;

Drawn::Drawn(){}
Drawn::~Drawn(){}
void Drawn::drawnMap(Map *map){
  map->chargeMaze();
  map->makeMaze();
}

void Drawn::drawnPlayer(Player *player){
  move(player->getPosy(), player->getPosx());
  addch(player->getSprite());
}
