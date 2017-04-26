#ifndef DRAWN_HPP
#define DRAWN_HPP
#include "map.hpp"
#include "player.hpp"

class Drawn{
    public:
      Drawn();
      ~Drawn();
      void drawnMap(Map *map);
      void drawnPlayer(Player *player);
};

#endif
