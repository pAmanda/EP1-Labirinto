#include<iostream>
#include <unistd.h>
#include <ncurses.h>
#include "drawn.hpp"
#include "map.hpp"

using namespace std;

Drawn::Drawn(){}

void Drawn::drawnMap(){
  Map *map = new Map();
  getch();
  map-> chargeMaze();
  map->makeMaze();
}
