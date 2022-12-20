
// Recommended order of include iostream, rest of standard library, third-partt library, local files
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

Bullet::~Bullet() {
    std::cout << "Enemy destroyed" << std::endl;
}

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

    int exitWindow = 0;
    int movement = 10;
    
    if (getRect().y <= exitWindow) {
        ses.remove(shared_from_this());
    } else 
        getRect().y-=movement;
}

