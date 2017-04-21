#include<iostream>
#include<ncurses.h>
#include<fstream>
#include "map.hpp"
#define LINHA 22
#define COLUNA 50
using namespace std;

Map::Map(){
  int l;
  int c;
  char a = ' ';

  for(l = 0; l < LINHA; ++l)
    for(c = 0; c < COLUNA; ++c){
       setMaze(a, l, c);
    }
}

void Map::setMaze(char a, int linha, int coluna){
    maze[linha][coluna] = a;
}

char Map::getMaze(int linha, int coluna){
  return maze[linha][coluna];
}

void Map::chargeMaze(){
   string line;
   ifstream map("maze.txt");

   if(map.is_open()){
     for(int l = 0; l < LINHA; ++l){
       getline(map, line);
       for(int c = 0; c < COLUNA; ++c){
         setMaze(line[c], l, c);
       }
     }
   }
  map.close();

}

void Map::makeMaze(){
  for(int l = 0; l < LINHA; ++l){
    for(int c = 0; c < COLUNA; ++c){
      move(l, c);
      printw("%c", getMaze(l, c));
    }
  }
}
