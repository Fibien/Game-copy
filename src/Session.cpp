﻿
// Ta bort iostream efter testning
#include <iostream>
#include "Session.h"

#define FPS 60

// Typedef has captital letter for every word
typedef std::shared_ptr<Sprite> SpritePtr;
typedef long long unsigned int LongUInt;

Session::Session(int x, int y, std::string title, std::string path) : syst_(x, y, title, path){
    max_x_ = x;
    max_y_ = y;
}

void Session::run(){


    is_session_running_ = true;
    //bool quit = false; // OK att ta bort?
    Uint32 tick_interval = 1000 / FPS;

    while(is_session_running_){

        Uint32 next_tick = SDL_GetTicks64() + tick_interval;
        SDL_Event event;

        handleEvent(event);

        clearRenderer();

        handleTick();

        handleCreatedElements();

        handleCollision();

        removeElements();

        renderBackground();

        invokeDraw();

        displayElements();

        int delay = determineDelay(next_tick);
        createDelay(delay);

    } // End outer while
} // End run






void Session::addSprite(const std::shared_ptr<Sprite>& sprite) {
    added_.push_back(std::move(sprite));
}

void Session::addPlayer(std::shared_ptr<Player> player){
    if(is_session_running_){
        throw std::invalid_argument("Players can't be added during runtime");
    }
    players_.push_back(player);
}

void Session::addHUD(HUD* hud){
     if(is_session_running_){
        throw std::invalid_argument("HUDs can't be added during runtime");
    }
    HUDs_.push_back(hud);
}

void Session::createTexture(std::initializer_list<input_pair> pairs){
    syst_.createTexture(pairs);
}

SDL_Texture* Session::getTexture(std::string key){
    return syst_.getTexture(key);
}

SDL_Renderer* Session::getRenderer() {
    return syst_.getRenderer();
}

void Session::remove(const std::shared_ptr<Sprite> &sprite) {
    removed_.push_back(std::move(sprite));
}

void Session::setWindow(int height, int width, SDL_Texture* texture) {
    syst_.setWindow(height, width, texture);
}

void Session::handleEvent(SDL_Event& event){

       while(SDL_PollEvent(&event)){
            
            // Sätt switch event i en metod
            switch(event.type){
            
                case SDL_KEYUP: {
                    for(std::shared_ptr<Player> player : players_){
                        player->keyUp(event, max_x_);
                        // std::cout << "Crashing" << std::endl;
                    }  
                break;
                }

                case SDL_KEYDOWN: {
                    for(std::shared_ptr<Player> player : players_){
                        //player->keyDown(event, max_x_, this); 
                        player->keyDown(event, max_x_);
                    }   
                    break;
                }
                // Ersätter quit med is_session_running_
                case SDL_QUIT: is_session_running_ = false; break;
        
            } // End of switch
        } // End of inner while loop

}

void Session::clearRenderer(){
    SDL_RenderClear(syst_.getRenderer());
}

void Session::handleTick(){

    for (auto sprite : sprites_) {
            sprite->tick();
        }

}

void Session::handleCreatedElements(){
    for (auto sprite : added_) {
        sprites_.push_back(std::move(sprite));
    }
       
    added_.clear();   
}

void Session::handleCollision(){

     if(sprites_.size() <= 1){
        return;
     }

    for(LongUInt i = 0; i < sprites_.size() - 1; i++){
        for(LongUInt j = (i + 1); j < sprites_.size(); j++){
            SpritePtr first = sprites_.at(i);
            SpritePtr second = sprites_.at(j);
                    
            bool collided = first->hasCollided(&first->getRect(), &second->getRect());
            if (collided) {
                first->getCollisionBehaviour();
                second->getCollisionBehaviour();
            }
                   
        } // inner for
    } // outer for
        
}

void Session::removeElements(){

     for (std::shared_ptr<Sprite> sprite : removed_) {
            for(std::vector<std::shared_ptr<Sprite>>::iterator i = sprites_.begin(); i != sprites_.end();){
                if(*i == sprite){
                    i = sprites_.erase(i);
                }
                else{
                    i++;
                }
            }
        }
        removed_.clear();
}

void Session::renderBackground(){
    SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);
}

void Session::invokeDraw(){

     for (auto sprite : sprites_) {
            sprite->draw();
     }

    for(std::shared_ptr<Player> player : players_){
            player->draw();
    }
}

void Session::displayElements(){
     SDL_RenderPresent(syst_.getRenderer());
}

int Session::determineDelay(Uint32 next_tick){
      return next_tick - SDL_GetTicks();
       
}

void Session::createDelay(int delay){
        if (delay > 0) {
            SDL_Delay(delay);
        }
}

Session ses(DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_TITLE, DEFAULT_BACKGROUND);