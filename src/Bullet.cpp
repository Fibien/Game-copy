#include "Bullet.h"
#include "Session.h"
#include <string.h>
#include <SDL2/SDL.h>

#include <iostream>


Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

Bullet* Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    return new Bullet(x,y,height,width,texture);
}

void Bullet::draw() {
    // std::cout << "Skjut" << std::endl;
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Bullet::tick() {
    if (getRect().y <= 0) {
        ses.remove(this);
    } else 
        getRect().y--;
}

Bullet::~Bullet() {

}