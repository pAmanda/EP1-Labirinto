#ifndef DRAWN_HPP
#define DRAWN_HPP
#include "map.hpp"
#include "player.hpp"

//Classe responsável por desenhar o mapa e o player na tela.
class Drawn{
    public:
      Drawn();
      ~Drawn();
      void drawnMap(Map *map);
      void drawnPlayer(Player *player);
};

#endif
