
// Ta bort iostream efter testning
#include <iostream>
#include <memory>
#include "Player.h"
#include "Bullet.h"

Player::~Player(){
    // Behöver något destrueras i Player?
    //std::cout << "Player destructor" << std::endl;
}

std::shared_ptr<Player> Player::getInstance(int x, int y, int h, int w, SDL_Texture* texture) {
    //return std::make_shared<Player>(x, y, h, w, texture);
    return std::shared_ptr<Player>(new Player(x, y, h, w, texture));
}

void Player::keyDown(SDL_Event& eve, int max_x_){

    int move = 5;

    if (eve.key.keysym.sym == SDLK_LEFT && this->getRect().x >= move) {
        this->getRect().x -= move; 
    }

    // Update size
    if (eve.key.keysym.sym == SDLK_RIGHT && this->getRect().x <= (max_x_-(this->getRect().w+move))) {
        this->getRect().x += move;
    }
}

void Player::keyUp(SDL_Event& eve, int x) {  
    if(eve.key.keysym.sym == SDLK_SPACE) {
                                                                                                            // Magic number                                                                       
        SDL_Texture* tex = ses.getTexture("Bullet");
        //std::shared_ptr<Sprite> bullet = Bullet::getInstance((this->getRect().x + (this->getRect().w/2)), this->getRect().y+10, 10, 20, tex);
        //ses.addSprite(std::move(bullet));
        ses.addSprite(Bullet::getInstance((this->getRect().x + (this->getRect().w/2)), this->getRect().y+10, 10, 20, tex));
    }
}

void Player::tick(){

} 

void Player::draw() { 
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

