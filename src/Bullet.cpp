﻿#include "Bullet.h"
#include "Session.h"
#include <string.h>
#include <SDL2/SDL.h>


Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

Bullet* Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    return new Bullet(x,y,height,width,texture);
}

void Bullet::draw(SDL_Renderer* ren) {
    std::cout << "Draw bullet" << std::endl;
    SDL_RenderCopy(ren, getTexture(), NULL, &getRect());
}

// void Bullet::tick(Session* ses) {
//     if (getRect().y <= 0)
        
//     getRect().y--;
// }

Bullet::~Bullet() {

}