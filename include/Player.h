#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <string>
#include <SDL2/SDL.h>


class Player : public Sprite{

    public:
    static Player* getInstance(int, int, int, int, std::string);
    void keyDown(SDL_Event&);
    void keyUp(SDL_Event&);
    void tick();
    void draw() const;
    ~Player();

    protected:
    Player(int x, int y, int height, int width, std::string path) : Sprite(x,y,height,width,path) {}

};



#endif