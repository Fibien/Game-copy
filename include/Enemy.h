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
    void getCollisionBehaviour();
    //void reachGoal(); // Implement?
    //bool enemyInFront(); // Implement?

    protected:
    Enemy(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture), height(height) {}

    private:
    static int shoot;
    static int rng;
    int move_count_{0};
    int move_tickCount_{0};
    int fire_tickCount{1};
    int height;
    bool goRight_{true};
    bool goDown_{false};
    void moveEnemy();
   
};



#endif