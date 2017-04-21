#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdio_ext.h>

#include "drawn.hpp"
using namespace std;

int main(){
  Drawn *drawn = new Drawn();
  while(TRUE){
    initscr();
    noecho();
    getch();
    drawn->drawnMap();
  }
  refresh();
  endwin();
  return 0;
}
