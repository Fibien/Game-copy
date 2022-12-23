#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <memory>
#include "HUD.h"

class ScoreBoard : public HUD {

    public:
    ~ScoreBoard() {}
    void increasePoints();
    void decreaseLife();
    void update();
    
    static std::shared_ptr<HUD> getInstance(int, int, int, int, std::string, std::string, int, 
    int pointsPerHit = 10, int lives = 3, int multiplier = 1);

    protected:
    ScoreBoard(int x, int y, int h, int w, std::string background, std::string path, int size, 
    int pointsPerHit, int lives, int multiplier);

    private:
    SDL_Rect rect_;
};

#endif
