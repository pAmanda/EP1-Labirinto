#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

//Classe base que possui características comum a outras classes.
class GameObject{
  private:
    char sprite;
    int posx;
    int posy;

  public:
    GameObject();
    ~GameObject();
    void setSprite(char sprite);
    char getSprite();
    void setPosx(int posx);
    int getPosx();
    void setPosy(int posy);
    int getPosy();

};

#endif
