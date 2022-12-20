#include "Enemy.h"
#include "Session.h"
#include <SDL2/SDL.h>

// Getinstance
Enemy* Enemy::getInstance(int x, int y, int height, int width, SDL_Texture* texture) {
    return new Enemy(x, y, height, width, texture);
}

void Enemy::tick() {

}

void Enemy::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

Enemy::~Enemy() {
    
}


