#ifndef DEVPLAYER_H
#define DEVPLAYER_H

#include <memory>
#include "Player.h"

class DevPlayer : public Player{

    public:
    static std::shared_ptr<Player> getInstance(int, int, int, int, std::string, int, int, int);
    ~DevPlayer() {}
    void moveRight();
    void moveLeft();
    void shoot_();

    protected:
    DevPlayer(int x, int y, int height_, int width, std::string background, int move, int higher_boundry, 
    int lower_boundry) : Player(x, y, height_, width, background), move_(move), 
    lower_boundry_(lower_boundry),higher_boundry_(higher_boundry) {}

    private:
    int move_;
    int lower_boundry_;
    int higher_boundry_;
};

#endif
