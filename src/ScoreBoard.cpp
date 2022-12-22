#include <string>
#include "ScoreBoard.h"
#include "Session.h"

std::shared_ptr<HUD> ScoreBoard::getInstance(int x, int y, int h, int w, std::string background, 
    std::string path_, int size, int pointsPerHit, int lives_, int multiplier_) {
    return std::shared_ptr<HUD>(new ScoreBoard(x,y,h,w,background, path_, size, pointsPerHit, 
    lives_, multiplier_));
}

void ScoreBoard::increasePoints(){
    addToTotalPoints(getPointsPerHit());
}

void ScoreBoard::decreaseLife(){
    subtractFromLives(getDamageMultiplier());
}

void ScoreBoard::update(){

    std::string lives_ = std::to_string(getRemaningLives());
    std::string points = std::to_string(getTotalPoints());
    std::string space = std::string(26, ' ');
    std::string newValue = "Lives: " + lives_ + space + "Score: " + points;
    setText(newValue, getSize(), getPath());

}
