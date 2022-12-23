#include "DevPlayer.h"
#include "Session.h"
#include "Bullet.h"
#include <memory>


std::shared_ptr<Player> DevPlayer::getInstance(int x, int y, int height_, int width, 
std::string background, int move, int higher_boundry, int lower_boundry){
    return std::shared_ptr<Player>(new DevPlayer(x,y,height_,width,background, move, 
    higher_boundry, lower_boundry));
}

void DevPlayer::moveRight(){
    if(this->getRect().x <= lower_boundry_ + move_){
        this->getRect().x += move_;
    }    
}

void DevPlayer::moveLeft(){
    if(this->getRect().x  >= higher_boundry_ + move_){
        this->getRect().x -= move_;
    }
}

void DevPlayer::shoot_(){

    int xMovement = this->getRect().x + (this->getRect().w/2);
    int yMovement = this->getRect().y - 20;   
 
    int width = 10;
    int height_ = 20;
    bool friendly = true;

    ses.addSprite(Bullet::getInstance(xMovement, yMovement, width, height_, "Bullet", friendly));
}