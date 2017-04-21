#include<iostream>
#include "player.hpp"
using namespace std;

Player::Player(){
  setSprite(' ');
  setPosx(0);
  setPosy(0);
}

Player::Player(char sprite, int posx, int posy){
  setSprite(sprite);
  setPosx(posx);
  setPosy(posy);
}

Player::~Player(){}

void Player::setSprite(char sprite){
  this->sprite = sprite;
}

char Player::getSprite(){
  return sprite;
}

void Player::setPosx(int posx){
  this->posx = posx;
}

int Player::getPosx(){
  return posx;
}

void Player::setPosy(int posy){
  this->posy = posy;
}

int Player::getPosy(){
  return posy;
}

void Player::movement(){}
