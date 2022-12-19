﻿#include "Player.h"
#include "Bullet.h"
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <functional>


Player::~Player(){
    std::cout << "Player destructor" << std::endl;
    // Hur gör man så att Sprite texture tags bort?
    //SDL_DestroyTexture(getTexture());
}

Player* Player::getInstance(int x, int y, int h, int w, SDL_Texture* texture) {
    return new Player(x, y, h, w, texture);
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
        Bullet* bullet = Bullet::getInstance((this->getRect().x + (this->getRect().w/2)), this->getRect().y+10, 10, 20, tex);
        ses.addSprite(bullet);
    }
}

void Player::tick(){

} 

void Player::draw() { 
    SDL_RenderCopy(ses.getRenderer(), getTexture(), NULL, &getRect());
}

