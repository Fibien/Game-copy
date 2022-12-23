#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include "Sprite.h"

class Enemy : public Sprite, public std::enable_shared_from_this<Enemy> {

    public:
    static std::shared_ptr<Enemy> getInstance(int, int, int, int, std::string);
    ~Enemy() {}
    void tick();
    void getCollisionBehaviour();

    protected:
    Enemy(int, int, int, int, std::string);

    private:
    void moveEnemy();
    const bool canEnemyShoot();
    const bool isNextRowClear();
    const bool isTwoRowsAwayClear();
    const bool canShoot(int);
    void shoot();
    static int shoot_;
    static int rng_;
    int move_count_{0};
    int move_tickCount_{0};
    int fire_tickCount{1};
    int height_;
    bool goRight_{true};
    bool goDown_{false};
};



#endif