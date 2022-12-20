
// Recommended order of include iostream, rest of standard library, third-partt library, local files
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include "Bullet.h"
#include "Session.h"
#include "Sprite.h"

Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    return std::make_shared<Bullet>(x,y,height,width,texture);
}

void Bullet::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Bullet::tick() {
    if (getRect().y <= 0) {
        ses.remove(shared_from_this());
    } else 
        getRect().y-=10;
}

void Bullet::getCollisionBehaviour() {
    ses.remove(shared_from_this());
}

Bullet::~Bullet() {
    std::cout << "Enemy destroyed" << std::endl;
}