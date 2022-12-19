#include "Bullet.h"
#include <string.h>
#include <SDL2/SDL.h>

Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x,y,height,width, texture){}

Bullet* Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture){
    return new Bullet(x,y,height,width,texture);
}

void Bullet::draw(SDL_Renderer* ren) {

}

void Bullet::tick() {

}

Bullet::~Bullet() {

}