#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "HUD.h"
#include <iostream>

class ScoreBoard : public HUD {

    public:
    ~ScoreBoard();
    void draw();
    void setText(std::string, int, std::string);
    void increasePoints();
    void decreaseLife();
    
    static std::shared_ptr<HUD> getInstance(int, int, int, int, SDL_Texture*, int points = 10, int lives = 3, int multiplier = 1);

    protected:
    ScoreBoard(int x, int y, int h, int w, SDL_Texture* txt, int points, int lives , int multiplier) : HUD(x,y,h,w,txt, points, lives, multiplier) { std::cout << "Scoreboard ctr";} 

    private:
    TTF_Font* font;
    SDL_Texture* textTexture;
    SDL_Rect rect_;

};

#endif
