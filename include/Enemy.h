#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include <SDL2/SDL.h>

class Enemy : public Sprite {

    public:
    static Enemy* getInstance(int, int, int, int, SDL_Texture*);
    void tick();
    void draw();
    ~Enemy();

    void reachGoal();
    bool enemyInFront();

    protected:
    Enemy(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture) {}

    private:
    
};

#endif