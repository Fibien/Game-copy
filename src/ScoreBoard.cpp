
#include "ScoreBoard.h"
#include "Session.h"
#include "Constants.h"
// #include "HUD.h"
#include <string>
#include <iostream>

void ScoreBoard::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}


std::shared_ptr<HUD> ScoreBoard::getInstance(int x, int y, int h, int w, SDL_Texture* txt, std::string path, int size, int points, int lives, int multiplier) {
    return std::shared_ptr<HUD>(new ScoreBoard(x,y,h,w,txt, path, size, points, lives, multiplier));
}

ScoreBoard::~ScoreBoard() {
    std::cout << "ScoreBoard destructor " << std::endl;
}

void ScoreBoard::increasePoints(){
    totalPoints += pointsPerHit;
}

void ScoreBoard::decreaseLife(){
    lives -= multiplier;
}
void ScoreBoard::update(){

    std::string lives = std::to_string(getRemaningLives());
    std::string points = std::to_string(getTotalPoints());
    std::string space = std::string(26, ' ');
    std::string newValue = "Lives: " + lives + space + "Score: " + points;
    setText(newValue, size, path);

}
