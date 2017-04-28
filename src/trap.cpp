#include<iostream>
#include "trap.hpp"
using namespace std;

Trap::Trap(){
  setDamage(0);
  setSprite('%');
  setPosy(0);
  setPosx(1);
}

Trap::~Trap(){}

void Trap::setDamage(int damage){
    this->damage += damage;
}

int Trap::getDamage(){
  return damage;
}
