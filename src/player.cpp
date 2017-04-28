#include<iostream>
#include "player.hpp"
#include "map.hpp"
#include<ncurses.h>
using namespace std;

Player::Player() { //Polimorfismo do tipo Sobrecarga de Construtor
  setAlive(true);
  setWinner(false);
}

Player::Player(char sprite, int posx, int posy){//Polimorfismo do tipo Sobrecarga de Construtor
  setSprite(sprite);
  setPosx(posx);
  setPosy(posy);
  setAlive(true);
  setWinner(false);
}

Player::~Player(){}

void Player::setAlive(bool alive){
  this->alive = alive;
}

bool Player::getAlive(){
  return alive;
}

void Player::setWinner(bool winner){
  this->winner = winner;
}

bool Player::getWinner(){
  return winner;
}
