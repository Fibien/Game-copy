#include "HUD.h"
#include "Session.h"
#include "Constants.h"

HUD::HUD(int x, int y, int w, int h, std::string background, std::string path_, int size, int points = 10, 
    int lives_ = 3, int damage_multiplier_ = 1) : rect_{x, y, w, h}, path_(path_), size_(size), 
    pointsPerHit_(points), lives_(lives_), damage_multiplier_(damage_multiplier_) 
    { text_texture_ = ses.getTexture(background); 
    };

HUD::~HUD(){
    SDL_DestroyTexture(text_texture_);
    TTF_CloseFont(font_);
    TTF_Quit();
}

void HUD::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void HUD::setText(std::string text, int size, std::string path_) {
    if (TTF_Init() == -1) {
        exit(-1);
    }

    font_ = TTF_OpenFont((constants::gResPath + path_).c_str(), size);
    SDL_Color color = {77,255,64};
    
    SDL_Surface* textSurf = TTF_RenderText_Solid(font_, text.c_str(), color);
    text_texture_ = SDL_CreateTextureFromSurface(ses.getRenderer(), textSurf);

    SDL_Rect& rect_ = getRect();
    rect_ = {rect_.x, rect_.y, textSurf->w, textSurf->h};

    SDL_RenderCopy(ses.getRenderer(), text_texture_, NULL, &rect_);
    SDL_FreeSurface(textSurf);
}

SDL_Texture* HUD::getTexture() {
    return text_texture_;
}

SDL_Rect& HUD::getRect() {
    return rect_;
}

void HUD::addToTotalPoints(int points){
    total_points_ += points;
}

void HUD::subtractFromLives(int damage){
    lives_ -= damage;
}

