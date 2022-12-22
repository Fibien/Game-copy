#include "Session.h"
#include "Sprite.h"

#include "iostream"

Sprite::Sprite(int x, int y, int w, int h, std::string background) : rect_{x,y,w,h}  {
    texture_ = ses.getTexture(background);
}

Sprite::~Sprite(){
     // Textures* are stored in a map in system.
     // Textures are shared between Sprites of the same kind
     // and do not need to be destroyed here
}

bool Sprite::hasCollided(const SDL_Rect* firstRect, const SDL_Rect* secondRect) {
    return SDL_HasIntersection(firstRect, secondRect);
}

void Sprite::draw() { 
    
    if(ses.getRenderer() == nullptr){
        std::cerr << "Rendered null" << std::endl;
    }

    if(getTexture() == nullptr){
        std::cerr << "Texture null" << std::endl;
    }



    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
    std::cerr << "Player-drqaw/(" << std::endl;
}

bool Sprite::operator==(const Sprite& other){
    return SDL_RectEquals(&this->rect_, &other.rect_);
}