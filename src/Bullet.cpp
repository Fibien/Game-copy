
// Recommended order of include iostream, rest of standard library, third-partt library, local files
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    //return std::make_shared<Bullet>(x,y,height,width,texture);
    return std::shared_ptr<Bullet>(new Bullet(x,y,height,width,texture)); 
}

void Bullet::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Bullet::getCollisionBehaviour() {
    ses.remove(shared_from_this());
}

void Bullet::tick() {

    // Magic number in if and else
    if (getRect().y <= 0) {
        ses.remove(shared_from_this());
    } else 
        getRect().y-=10;
}

Bullet::~Bullet() {
    std::cout << "Enemy destroyed" << std::endl;
}