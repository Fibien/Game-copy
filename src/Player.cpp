#include "Player.h"
#include <string>
#include "Session.h"
#include <SDL2/SDL.h>
#include <iostream>


Player::~Player(){
    std::cout << "Player destructor" << std::endl;
    //SDL_DestroyTexture(getTexture());
}

Player* Player::getInstance(int x, int y, int h, int w, SDL_Texture* texture) {
    return new Player(x, y, h, w, texture);
}

// Ha kvar max y?
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

}

void Player::tick(){

} 

void Player::draw(SDL_Renderer* ren) { 
    SDL_RenderCopy(ren, getTexture(), NULL, &getRect());
}

