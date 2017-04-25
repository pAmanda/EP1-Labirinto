#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<iostream>
#include "gameObject.hpp"

class Player : public GameObject{
  private:
    bool alive;
    int score;
    bool winner;

  public:
    Player();
    Player(char sprite, int posx, int posy) ;
    ~Player();
    void setAlive(bool alive);
    bool getAlive();
    void setScore(int score);
    int getScore();
    void setWinner(bool winner);
    bool getWinner();
    void movement();
};

#endif
