#include "Bullet.h"
#include "Session.h"
#include <string.h>
#include <SDL2/SDL.h>
#include <memory>

#include <iostream>


Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    //std::shared_ptr<Bullet> ptr = std::make_shared<Bullet>(x,y,height,width,texture);
    // ptr(new Bullet(x,y,height,width,texture));
    return std::make_shared<Bullet>(x,y,height,width,texture);
}

void Bullet::draw() {
    // std::cout << "Draw bullet" << std::endl;
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
    if (getTexture() == nullptr) {
        std::cout << "NULL" << std::endl;
    }

}

void Bullet::tick() {
    if (getRect().y <= 0) {
        //ses.remove(this);
        ses.removedTest(shared_from_this());
    } else 
        getRect().y--;
}

Bullet::~Bullet() {
    std::cout << "Enemy destroyed" << std::endl;
}