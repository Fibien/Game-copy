#include "Sprite.h"
#include <SDL2/SDL.H>
#include <SDL2/SDL_image.h>
#include <string>
#include "System.h"
#include "Constants.h"

// Ska lägga till värdena i rektangeln

 Sprite::Sprite(int x, int y, int w, int h, SDL_Texture* texture_) : rect_{x,y,w,h}, texture_(texture_) {}