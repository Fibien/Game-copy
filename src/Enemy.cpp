#include <stdio.h>
#include <memory>
#include "Enemy.h"
#include "Session.h"
#include "Bullet.h"

typedef long long unsigned int LongUInt;

std::shared_ptr<Enemy> Enemy::getInstance(int x, int y, int height_, int width, std::string background) {
    return std::shared_ptr<Enemy>(new Enemy(x, y, height_, width, background));
}

Enemy::Enemy(int x, int y, int height_, int width, std::string background) : Sprite(x, y, height_, width, background), height_(height_) {}

void Enemy::tick() {

    moveEnemy();

    if(!(fire_tickCount++ % 50 == 0) || move_count_ >= 3){
        return;
    }

    bool canShoot = canEnemyShoot();
    
    if(canShoot && shoot_++ == rng_) {
        shoot();
    } 
}

void Enemy::getCollisionBehaviour(){
    ses.remove(shared_from_this());
    std::shared_ptr<HUD> hud = ses.getHUD();

    hud->increasePoints();
    hud->update();
}

void Enemy::moveEnemy(){
    if(!(move_tickCount_++ % 100 == 0)){
        return;
    } 

    if(goRight_ && move_count_ <= 3){
        getRect().x += 40;
        move_count_++;
    }

    if(move_count_ == 4){
        goDown_ = true;
        goRight_ = !goRight_;
        move_count_ = 0;       
    }

    if(goDown_){
        getRect().y += 20;
        goDown_= false;
    }

    if(!goRight_ && move_count_ <= 4){
        getRect().x -= 40;
        move_count_++;
    }
    
    if(this->getRect().y + this->getRect().h > ses.getMaxY()) {
        ses.looseTheGame();
    }
}

const bool Enemy::canEnemyShoot(){
    
    std::vector<std::shared_ptr<Sprite>> sprites_ = ses.getSpriteVec();
    bool canShoot = true;
    int offset = 10;

    for(LongUInt i = 0; i < sprites_.size(); i++){

        int x = getRect().x;
        int y = getRect().y + getRect().h + offset;

        std::shared_ptr<Sprite> sprite2 = sprites_.at(i);
        int xTwo = sprite2->getRect().x;
        int yTwo = sprite2->getRect().y;    
        
        if(x == xTwo && y == yTwo){
            canShoot = false;
        }
    
    } // for  

    return canShoot;
}

void Enemy::shoot(){

    int xMovement = this->getRect().x + (this->getRect().w/2);
    int yMovement = this->getRect().y + 50;   
    int width = 10;
    int height_ = 20;
    int playerBullet = false;

    std::shared_ptr<Sprite> bullet =  Bullet::getInstance(xMovement, yMovement, width, 
        height_, "Bullet", playerBullet);
    ses.addSprite(bullet);
    shoot_ = 0;
    rng_ = rand() % 10;
}

// static variable
int Enemy::shoot_ = 0;
int Enemy::rng_ = rand() % 20;