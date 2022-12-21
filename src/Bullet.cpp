
// Recommended order of include iostream, rest of standard library, third-party library, local files
#include "Bullet.h"
// Testing
#include <iostream>


Bullet::Bullet(int x, int y, int height, int width, SDL_Texture* texture, bool shotFromPlayer) : Sprite(x,y,height,width, texture), shotFromPlayer(shotFromPlayer) {}

Bullet::~Bullet() {
    std::cout << "Bullet destroyed" << std::endl;
}

std::shared_ptr<Bullet> Bullet::getInstance(int x, int y, int height, int width, SDL_Texture* texture, bool shotFromPlayer){
    return std::shared_ptr<Bullet>(new Bullet(x,y,height,width,texture, shotFromPlayer)); 
}

void Bullet::draw() {
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Bullet::getCollisionBehaviour() {
    ses.remove(shared_from_this());
}

void Bullet::tick() {

    if(shotFromPlayer){

        int exitWindow = 0;
        int movement = 7;

        if (getRect().y <= exitWindow) {
            ses.remove(shared_from_this());
        } else 
            getRect().y-=movement;

    } else{
            
        int exitWindow = ses.getMaxY();
        int movement = 3;

        if (getRect().y >= exitWindow) {
            ses.remove(shared_from_this());
        } else 
            getRect().y+=movement;
    }
}



