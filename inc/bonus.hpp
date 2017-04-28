#ifndef BONUS_HPP
#define BONUS_HPP
#include "gameObject.hpp"

//Bonus da jogador
class Bonus : public GameObject{
  private:
    int score;
  public:
    Bonus();
    ~Bonus();
    void setScore(int score);
    int getScore();
};
#endif
