#ifndef TRAP_HPP
#define TRAP_HPP
#include "gameObject.hpp"

//Armadilhas do jogo
class Trap : public GameObject{
    private:
      int damage;

    public:
      Trap();
      ~Trap();
      void setDamage(int damage);
      int getDamage();
};
#endif
