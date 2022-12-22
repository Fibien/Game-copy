#include "HUD.h"
#include "Session.h"
#include "Constants.h"

void HUD::setPointsPerHit(int points){

}

void setLives(int lives){

}


void setDamageTakenPerHit(int multiplier){

}

SDL_Texture* HUD::getTexture() {
    return textTexture;
}

SDL_Rect& HUD::getRect() {
    return rect_;
}

HUD::~HUD(){
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
}

void HUD::setText(std::string text, int size, std::string path) {
    if (TTF_Init() == -1) {
        exit(-1);
    }
    // std::cout << "Open font " << std::endl;
    font = TTF_OpenFont((constants::gResPath + path).c_str(), size);
    // std::cout << "Nullfont" << (font == nullptr) << std::endl;
    // std::cout << "Open color " << std::endl;
    SDL_Color color = {77,255,64};
    
    // std::cout << "Open textsurf " << std::endl;
    SDL_Surface* textSurf = TTF_RenderText_Solid(font, text.c_str(), color);
    // std::cout << "CreateTexture " << std::endl;
    textTexture = SDL_CreateTextureFromSurface(ses.getRenderer(), textSurf);
    // std::cout << "set Rect " << std::endl;
    SDL_Rect& rect_ = getRect();
    rect_ = {rect_.x, rect_.y, textSurf->w, textSurf->h};
    //rect_ = {x, y, textSurf->w, textSurf->h};
    // std::cout << "Render copy " << std::endl;
    SDL_RenderCopy(ses.getRenderer(), textTexture, NULL, &rect_);
    // std::cout << "Freesurface " << std::endl;
    SDL_FreeSurface(textSurf);
    // std::cout << "End of method " << std::endl;
}