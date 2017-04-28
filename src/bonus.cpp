#include<iostream>
#include"bonus.hpp"
using namespace std;

Bonus::Bonus(){
  setScore(0);
  setSprite('-');
}

Bonus::~Bonus(){}

void Bonus::setScore(int score){
  this->score = score;
}
 int Bonus::getScore(){
   return score;
 }
