#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite{

    public:
    virtual ~Player() {}
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    virtual void shoot_() = 0;  
    void tick();
    void getCollisionBehaviour();
   
    protected:
    Player(int x, int y, int height, int width, std::string background) : Sprite(x, y, height, width, background) {}
};

#endif