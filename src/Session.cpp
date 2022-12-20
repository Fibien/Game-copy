#include <algorithm>
#include <stdexcept>
#include "System.h"
#include "Session.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>
#include <memory>
#include <vector>

#define FPS 60
//#include "Pl"

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
                    for(Player *player : players_){
                        player->keyUp(event, max_x_);
                        // std::cout << "Crashing" << std::endl;
                    }  
                break;
                }

                case SDL_KEYDOWN: {
                    for(Player *player : players_){
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
            // std::cout << "Bullet " << c << std::endl; 
            sprite->tick();
            // c++;
        }

        // Lägga till element i en metod
        // // Lägga till element (och HUD?)
        // for (Sprite *sprite : added)
        //     sprites.push_back(sprite);   
        // added.clear();

        for (auto sprite : added_) {
            sprites_.push_back(std::move(sprite));

        }
        added_.clear();       
     
        // Test method to remove bullets
        int nr = 0;

        for (std::shared_ptr<Sprite> sprite : removed_) {
            for(std::vector<std::shared_ptr<Sprite>>::iterator i = sprites_.begin(); i != sprites_.end();){
                std::cout << "Sprite: " << nr++ << std::endl;
                std::cout << "Count: "<< sprite.use_count() << std::endl;
                if(*i == sprite){
                    std::cout << "De är lika" << std::endl;
                    i = sprites_.erase(i);
                }
                else{
                    i++;
                    std::cout << "De är olika" << std::endl;
                }
                std::cout << "Count: "<< sprite.use_count() << std::endl;
            }
        }
        removed_.clear();

        SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);

        // de olika draw i en eller flera metoder
        // for (Sprite *sprite : sprites)
        //    sprite->draw();

        for (auto sprite : sprites_) {
            sprite->draw();

        }



        for(Player *player : players_){
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
void Session::addPlayer(Player *player){
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