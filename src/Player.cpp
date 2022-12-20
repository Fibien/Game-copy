
// Ta bort iostream efter testning
#include <iostream>
#include <memory>
#include "Player.h"
#include "Bullet.h"

Player::~Player(){
    // Behöver något destrueras i Player?
}

std::shared_ptr<Player> Player::getInstance(int x, int y, int h, int w, SDL_Texture* texture) {
    //return std::make_shared<Player>(x, y, h, w, texture);
    return std::shared_ptr<Player>(new Player(x, y, h, w, texture));
}

void Player::draw() { 
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

void Player::keyDown(SDL_Event& eve, int max_x_){

    int move = 5;
    int lowerBoundry = move;
    int higherBoundry = (max_x_-(this->getRect().w+move));

    if (eve.key.keysym.sym == SDLK_LEFT && this->getRect().x >= lowerBoundry) {
        this->getRect().x -= move; 
    }

    if (eve.key.keysym.sym == SDLK_RIGHT && this->getRect().x <= higherBoundry) {
        this->getRect().x += move;
    }
}

void Player::keyUp(SDL_Event& eve, int x) {  
    if(eve.key.keysym.sym == SDLK_SPACE) {
                                                                                                                                                                     
        SDL_Texture* tex = ses.getTexture("Bullet");
        int xMovement = this->getRect().x + (this->getRect().w/2);
        int yMovement = this->getRect().y + 10;   
        int width = 10;
        int height = 20;

        ses.addSprite(Bullet::getInstance(xMovement, yMovement, width, height, tex));
    }
}

void Player::tick(){

} 

