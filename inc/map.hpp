#ifndef MAP_HPP
#define MAP_HPP

#define LINHA 22
#define COLUNA 50

class Map{
      private:
        char maze[LINHA][COLUNA];

      public:
        Map();
        void setMaze(char a, int linha, int coluna);
        char getMaze(int linha, int coluna);
        void chargeMaze();
        void makeMaze();
};

#endif
