#include "Sprite.h"
#include <SDL2/SDL.H>
#include <SDL2/SDL_image.h>
#include <string>
#include "System.h"
#include "Constants.h"

Sprite::Sprite(int x, int y, int height, int width, std::string path){

    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    texture_ = IMG_LoadTexture(syst_.getRenderer(), (constants::gResPath + path).c_str());
};


