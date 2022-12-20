#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include "Sprite.h"

class Enemy : public Sprite, public std::enable_shared_from_this<Enemy> {

    public:
    static std::shared_ptr<Enemy> getInstance(int, int, int, int, SDL_Texture*);
    ~Enemy();
    void tick();
    void draw();
    void reachGoal();
    void getCollisionBehaviour();
    //bool enemyInFront();

    protected:
     // Ctr moved from public to protected
    Enemy(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture) {}
   
    
};

#endif