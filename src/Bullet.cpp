#include "Bullet.h"

Bullet::Bullet(int x, int y, int height_, int width, std::string background, bool shot_from_player) 
: Sprite(x, y, height_, width, background), shot_from_player_(shot_from_player) {}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height_, int width, 
std::string key, bool shot_from_player){
    return std::shared_ptr<Bullet>(new Bullet(x,y,height_,width, key, shot_from_player)); 
}

void Bullet::getCollisionBehaviour() {
    ses.remove(shared_from_this());
}

void Bullet::tick() {

    if(shot_from_player_){

        int exitWindow = 0;
        int movement = 7;

        if (getRect().y <= exitWindow) {
            ses.remove(shared_from_this());
        } else 
            getRect().y-=movement;

    } else{ // Shot from enemy
            
        int exitWindow = ses.getMaxY();
        int movement = 3;

        if (getRect().y >= exitWindow) {
            ses.remove(shared_from_this());
        } else 
            getRect().y+=movement;
    }
}