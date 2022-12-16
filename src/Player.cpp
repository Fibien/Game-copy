#include "Player.h"
#include <string>
#include "Session.h"
#include <SDL2/SDL.h>
#include <iostream>


Player::~Player(){
    std::cout << "Player destructor" << std::endl;
    //SDL_DestroyTexture(getTexture());
}

Player* Player::getInstance(int x, int y, int h, int w, std::string path) {
    return new Player(x, y, h, w, path);
}


void Player::keyDown(SDL_Event& eve){
    if (eve.key.keysym.sym == SDLK_LEFT) {
        this->getRect().x--; 
    }
    if (eve.key.keysym.sym == SDLK_RIGHT) {
        this->getRect().x++;
    }
    // SDL_Rect rect = getRect();
}

void Player::keyUp(SDL_Event& eve) {
    
}

void Player::tick(){

} 


void Player::draw() const {
   
    SDL_RenderCopy(syst_.getRenderer(), getTexture(), NULL, &getRect());
}

