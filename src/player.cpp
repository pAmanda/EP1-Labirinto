#include<iostream>
#include "player.hpp"
#include "map.hpp"
#include<ncurses.h>
using namespace std;

Player::Player() {
  setAlive(true);
  setScore(0);
  setWinner(false);
}

Player::Player(char sprite, int posx, int posy){
  setSprite(sprite);
  setPosx(posx);
  setPosy(posy);
  setAlive(true);
  setScore(0);
  setWinner(false);
}

Player::~Player(){}

void Player::setAlive(bool alive){
  this->alive = alive;
}

bool Player::getAlive(){
  return alive;
}

void Player::setScore(int score){
  this->score = score;
}

int Player::getScore(){
  return score;
}

void Player::setWinner(bool winner){
  this->winner = winner;
}

bool Player::getWinner(){
  return winner;
}
