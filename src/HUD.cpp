#include "HUD.h"

void HUD::setPointsPerHit(int points){

}

void setLives(int lives){

}


void setDamageTakenPerHit(int multiplier){

}

SDL_Texture* HUD::getTexture() {
    return tex_;
}

SDL_Rect& HUD::getRect() {
    return rect_;
}

HUD::~HUD(){

}