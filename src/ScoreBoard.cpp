
#include "ScoreBoard.h"
#include "Session.h"
#include "Constants.h"
#include <string>
#include <iostream>

void ScoreBoard::draw() {
    SDL_RenderCopy(ses.getRenderer(), textTexture, NULL, &getRect());
    //SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &rect_);
}

void ScoreBoard::setText(std::string text, int size, std::string path) {
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

std::shared_ptr<HUD> ScoreBoard::getInstance(int x, int y, int h, int w, SDL_Texture* txt, int points, int lives, int multiplier) {
    return std::shared_ptr<HUD>(new ScoreBoard(x,y,h,w,txt, points, lives, multiplier));
}

ScoreBoard::~ScoreBoard() {
    std::cout << "ScoreBoard dectructor " << std::endl;
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
}

void ScoreBoard::increasePoints(){
    totalPoints += pointsPerHit;
}

void ScoreBoard::decreaseLife(){
    lives -= multiplier;
}
