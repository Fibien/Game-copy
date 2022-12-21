#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite{

    public:
    static std::shared_ptr<Player> getInstance(int, int, int, int, SDL_Texture*);
    ~Player();
    void draw();
    void keyDown(SDL_Event&, int);
    void keyUp(SDL_Event&, int);
    void tick();
    void getCollisionBehaviour();
   

    protected:
    Player(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture) {}

};

#endif