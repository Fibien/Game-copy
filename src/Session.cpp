#include <algorithm>
#include <stdexcept>
#include "System.h"
#include "Session.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>
#include <memory>
#include <vector>
#include <stdio.h>

#define FPS 60

typedef std::shared_ptr<Sprite> sprite_ptr;

Session::Session(int x, int y, std::string title, std::string path) : syst_(x, y, title, path){
    max_x_ = x;
    max_y_ = y;
}

void Session::run(){

    

    // Refaktorera de två bool till en?
    is_session_running_ = true;
    bool quit = false;
    Uint32 tick_interval = 1000 / FPS;

    while(!quit){

        Uint32 next_tick = SDL_GetTicks() + tick_interval;
        SDL_Event event;
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
                case SDL_QUIT: quit = true; break;
        
            } // End of switch
        } // End of inner while loop

        SDL_RenderClear(syst_.getRenderer());

        for (auto sprite : sprites_) {
            sprite->tick();
        }

        // Lägga till element i en metod
        // // Lägga till element (och HUD?)
 
        // std::cerr << "Size of added " << added_.size() << std::endl;
        // std::cerr << "Size before adding " << sprites_.size() << std::endl;
        for (auto sprite : added_) {
            sprites_.push_back(std::move(sprite));
        }
        // std::cerr << "Size After adding " << sprites_.size() << std::endl;
        added_.clear();       
        
        int j = 0;
        for (int i = 0; i < sprites_.size(); i++) {
            std::cerr << "Element " << j++ << "coordinate: " << sprites_[i]->getRect().y << "Address: " << &(*sprites_[i]) << std::endl;
        }
        std::cerr << "---------------------" << std::endl;
        std::cerr << "Before collision" << std::endl;
        
        if(sprites_.size() > 1){

            for(auto i = 0; i < sprites_.size() - 1; i++){
                for(auto j = (i + 1); j < sprites_.size(); j++){
                    sprite_ptr first = sprites_.at(i);
                    sprite_ptr second = sprites_.at(j);
                    
                    //// Varför kollision?
                    //if (!((*first) == (*second))) {
                        bool collided = first->hasCollided(&first->getRect(), &second->getRect());
                        if (collided) {
                            first->getCollisionBehaviour();
                            second->getCollisionBehaviour();
                        }
                    //}    
                    //else{
                    //    std::cerr << "Lika i: " << &(*first) << " & j: " << &(*second) << std::endl;
                    
                        // SDL_Rect rect1 = first->getRect();
                        // SDL_Rect rect2 = second->getRect();
                        // std::printf("Rect 1: x: %d, y: %d, w: %d, h: %d\n", rect1.x, rect1.y, rect1.w, rect1.h);
                        // std::printf("Rect 2: x: %d, y: %d, w: %d, h: %d\n", rect2.x, rect2.y, rect2.w, rect2.h);
                    //}
                } // inner for
            } // outer for
        }

        std::cerr << "After collison" << std::endl;

        // std::cerr << "After collision loop" << std::endl;
        for (std::shared_ptr<Sprite> sprite : removed_) {
            for(std::vector<std::shared_ptr<Sprite>>::iterator i = sprites_.begin(); i != sprites_.end();){
                if(*i == sprite){
                    // std::cout << "De är lika" << std::endl;
                    i = sprites_.erase(i);
                }
                else{
                    i++;
                    // std::cout << "De är olika" << std::endl;
                }
            }
        }
        removed_.clear();

        SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);

        // de olika draw i en eller flera metoder

        for (auto sprite : sprites_) {
            sprite->draw();
        }

        for(std::shared_ptr<Player> player : players_){
            player->draw();
        }

        SDL_RenderPresent(syst_.getRenderer());
        // FPS delay
        
        int delay = next_tick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }

    } // End outer while
} // End run


// Test
void Session::addSprite(const std::shared_ptr<Sprite>& sprite) {
    added_.push_back(std::move(sprite));
}

void Session::remove(const std::shared_ptr<Sprite> &sprite) {
    removed_.push_back(std::move(sprite));
}

// Kolla om de pekar på samma obj
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

//Förslag på ändring, gör att vi blir av med några magic number
//Session ses(800, 600, "game", "./images/Background.jpg");
Session ses(DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_TITLE, DEFAULT_BACKGROUND);