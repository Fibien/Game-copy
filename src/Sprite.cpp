#include "Sprite.h"
#include <SDL2/SDL.H>
#include <SDL2/SDL_image.h>
#include <string>
#include "System.h"
#include "Constants.h"

// Ska lägga till värdena i rektangeln

 Sprite::Sprite(int x, int y, int w, int h, std::string path): rect_{x,y,w,h} {
    texture_ = IMG_LoadTexture(syst_.getRenderer(), (constants::gResPath + path).c_str());
}