
#include "Enemy.h"
#include "Session.h"

// Getinstance
std::shared_ptr<Enemy> Enemy::getInstance(int x, int y, int height, int width, SDL_Texture* texture) {
    //return std::make_shared<Enemy>(x, y, height, width, texture);
    return std::shared_ptr<Enemy>(new Enemy(x, y, height, width, texture));
}

Enemy::~Enemy() {
    
}

void Enemy::tick() {

}

void Enemy::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}


void Enemy::getCollisionBehaviour(){
    ses.remove(shared_from_this());
}


