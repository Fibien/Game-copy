#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "HUD.h"
#include <iostream>

class ScoreBoard : public HUD {

    public:
    ~ScoreBoard();
    void draw();
    void increasePoints();
    void decreaseLife();
    void update();
    
    static std::shared_ptr<HUD> getInstance(int, int, int, int, SDL_Texture*, std::string, int, int points = 10, int lives = 3, int multiplier = 1);

    protected:
    ScoreBoard(int x, int y, int h, int w, SDL_Texture* txt, std::string path, int size, int points, int lives , int multiplier) : HUD(x,y,h,w,txt, path, size, points, lives, multiplier){ std::cout << "Scoreboard ctr";} 

    private:
    SDL_Rect rect_;
};

#endif
