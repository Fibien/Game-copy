
#include "Enemy.h"
#include "Session.h"
#include "Bullet.h"
#include <stdio.h>
#include <stdlib.h>

// Testing
#include <iostream>

typedef long long unsigned int LongUInt;

// Getinstance
std::shared_ptr<Enemy> Enemy::getInstance(int x, int y, int height, int width, SDL_Texture* texture) {
    return std::shared_ptr<Enemy>(new Enemy(x, y, height, width, texture));
}

Enemy::~Enemy() {
    std::cout << "Enemy destroyed" << std::endl;
}

void Enemy::tick() {

    moveEnemy();

    // Pröva med &&
    if(!(fire_tickCount++ % 50 == 0) || move_count_ >= 3){
        return;
    }

    std::vector<std::shared_ptr<Sprite>> sprites_ = ses.getSpriteVec();
    bool canShoot = true;
    int offset = 10;

    for(LongUInt i = 0; i < sprites_.size(); i++){
        
        SDL_Rect rect = this->getRect();
        int x = rect.x;
        int y = rect.y + rect.h + offset;

        std::shared_ptr<Sprite> sprite2 = sprites_.at(i);
        SDL_Rect* rect2 = &(sprite2->getRect());
        int x2 = rect2->x;
        int y2 = rect2->y;       
        
        if(x == x2 && y == y2){
            canShoot = false;
        }
    } // for      
    
    if(canShoot && shoot++ == rng) {

        SDL_Texture* tex = ses.getTexture("Bullet");
        int xMovement = this->getRect().x + (this->getRect().w/2);
        int yMovement = this->getRect().y + 50;   
        int width = 10;
        int height = 20;
        int playerBullet = false;
        std::shared_ptr<Sprite> bullet =  Bullet::getInstance(xMovement, yMovement, width, height, tex, playerBullet);
        ses.addSprite(bullet);
        shoot = 0;
        rng = rand() % 10;
    } 
}

void Enemy::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Enemy::getCollisionBehaviour(){
    ses.remove(shared_from_this());
}

void Enemy::moveEnemy(){

     if(!(move_tickCount_++ % 100 == 0)){
        return;
    } 

    if(goRight_ && move_count_ <= 3){
        SDL_Rect& rect = getRect();
        rect.x += 40;
        move_count_++;
    }

    if(move_count_ == 4){
        goDown_ = true;
        goRight_ = !goRight_;
        move_count_ = 0;       
    }

    if(goDown_){
        SDL_Rect& rect = getRect();
        rect.y += 20;
        goDown_= false;
    }

    if(!goRight_ && move_count_ <= 4){
        SDL_Rect& rect = getRect();
        rect.x -= 40;
        move_count_++;
    }
}

// static variable
int Enemy::shoot = 0;
int Enemy::rng = rand() % 20;