#include "Sprite.h"
#include <SDL2/SDL.H>
#include <SDL2/SDL_image.h>
#include <string>
#include "System.h"
#include "Constants.h"

Sprite::Sprite(int x, int y, int w, int h, SDL_Texture* texture_) : rect_{x,y,w,h}, texture_(texture_) {}

bool Sprite::hasCollided(const SDL_Rect* firstRect, const SDL_Rect* secondRect) {
return SDL_HasIntersection(firstRect, secondRect);
}

bool Sprite::operator==(const Sprite& other){
    return SDL_RectEquals(&this->rect_, &other.rect_);
}