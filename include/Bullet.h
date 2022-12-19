#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"
#include <string>
#include <SDL2/SDL.h>
#include "Session.h"

// class Session;

class Bullet : public Sprite{

    public:
    static Bullet* getInstance(int, int, int, int, SDL_Texture*);
    ~Bullet();
    void draw(SDL_Renderer*);
    // void tick(Session*);

    protected:
    Bullet(int, int, int, int, SDL_Texture*);    

    private:

};

#endif