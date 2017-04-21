#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
  private:
    char sprite;
    int posx;
    int posy;

  public:
    Player();
    Player(char sprite, int posx, int posy);
    ~Player();
    void setSprite(char sprite);
    char getSprite();
    void setPosx(int posx);
    int getPosx();
    void setPosy(int posy);
    int getPosy();
    void movement();

};

#endif
