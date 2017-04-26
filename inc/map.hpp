#ifndef MAP_HPP
#define MAP_HPP
#include<ncurses.h>
#define LINE 22
#define COLUMN 50

class Map{
      private:
        char maze[LINE][COLUMN];

      public:
        Map();
        ~Map();
        void setMaze(char a, int lin, int col);
        char getMaze(int lin, int col);
        void chargeMaze();
        void makeMaze();
};
#endif
