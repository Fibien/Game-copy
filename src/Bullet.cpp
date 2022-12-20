#include "Bullet.h"
#include "Session.h"
#include <string.h>
#include <SDL2/SDL.h>
#include <memory>

#include <iostream>


Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    return std::make_shared<Bullet>(x,y,height,width,texture);
}

void Bullet::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Bullet::tick() {
    if (getRect().y <= 0) {
        //ses.remove(this);
        ses.remove(shared_from_this());
    } else 
        getRect().y--;
}

void Bullet::getCollisionBehaviour() {
    ses.remove(shared_from_this());
}

Bullet::~Bullet() {
    std::cout << "Enemy destroyed" << std::endl;
}