#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include <functional>
// #include "Session.h"

class Session;

class Player : public Sprite{

    public:
    static Player* getInstance(int, int, int, int, SDL_Texture*);
    //void keyDown(SDL_Event&, int, std::function<SDL_Texture*(std::string)>);
    void keyDown(SDL_Event&, int, Session*);
    void keyUp(SDL_Event&, int);
    // void tick(Session*);
    void draw(SDL_Renderer*);
    ~Player();

    protected:
    Player(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture) {}

};



#endif