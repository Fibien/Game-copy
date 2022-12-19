#include "Player.h"
#include "Session.h"
#include "Bullet.h"
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <functional>


Player::~Player(){
    std::cout << "Player destructor" << std::endl;
    //SDL_DestroyTexture(getTexture());
}

Player* Player::getInstance(int x, int y, int h, int w, SDL_Texture* texture) {
    return new Player(x, y, h, w, texture);
}

// Städa metoden, lägga in bordermin och bordermax?

void Player::keyDown(SDL_Event& eve, int max_x_ , Session* ses){

    int move = 5;

    if (eve.key.keysym.sym == SDLK_LEFT && this->getRect().x >= move) {
        this->getRect().x -= move; 
    }
    // Update size
    if (eve.key.keysym.sym == SDLK_RIGHT && this->getRect().x <= (max_x_-(this->getRect().w+move))) {
        this->getRect().x += move;
    }
    if(eve.key.keysym.sym == SDLK_SPACE) {
      
        std::cout << "Trycker på space" << std::endl;
        SDL_Texture* tex = ses->getTexture("Bullet");
        Bullet* bullet = Bullet::getInstance((this->getRect().x + (this->getRect().w/2)), this->getRect().y+10, 10, 20, tex);
        ses->addSprite(bullet);
    }
}


void Player::keyUp(SDL_Event& eve, int x) {}

void Player::tick(){

} 

void Player::draw(SDL_Renderer* ren) { 
    SDL_RenderCopy(ren, getTexture(), NULL, &getRect());
}

