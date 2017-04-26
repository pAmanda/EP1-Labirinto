#include<iostream>
#include<fstream>
#include "map.hpp"
#define LINE 22
#define COLUMN 50
using namespace std;

Map::Map(){
  int l;
  int c;
  char a = ' ';

  for(l = 0; l < LINE; ++l)
    for(c = 0; c < COLUMN; ++c){
       setMaze(a, l, c);
    }
}

Map::~Map(){}

void Map::setMaze(char a, int lin, int col){
    maze[lin][col] = a;
}

char Map::getMaze(int lin, int col){
  return maze[lin][col];
}

void Map::chargeMaze(){
   string line;
   ifstream map("maze.txt");

   if(map.is_open()){
     for(int l = 0; l < LINE; ++l){
       getline(map, line);
       for(int c = 0; c < COLUMN; ++c){
         setMaze(line[c], l, c);
       }
     }
   }
  map.close();

}

void Map::makeMaze(){
  for(int l = 0; l < LINE; ++l){
    for(int c = 0; c < COLUMN; ++c){
      move(l, c);
      addch(getMaze(l, c));
    }
  }
}
