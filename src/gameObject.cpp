#include<iostream>
#include "gameObject.hpp"
using namespace std;

GameObject::GameObject(){
  setSprite(' ');
  setPosx(0);
  setPosy(0);
}

GameObject::~GameObject(){}

void GameObject::setSprite(char sprite){
  this->sprite = sprite;
}

char GameObject::getSprite(){
  return sprite;
}

void GameObject::setPosx(int posx){
  this->posx = posx;
}

int GameObject::getPosx(){
  return posx;
}

void GameObject::setPosy(int posy){
  this->posy = posy;
}

int GameObject::getPosy(){
  return posy;
}
