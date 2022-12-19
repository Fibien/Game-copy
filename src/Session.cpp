#include <algorithm>
#include <stdexcept>
#include "System.h"
#include "Session.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>

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

        // Uint32 next_tick = SDL_GetTicks() + tick_interval;
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

        // Tick i en metod
        //  Tick för sprites
        for (Sprite *sprite : sprites) 
           sprite->tick();
  
        // Lägga till element i en metod
        // // Lägga till element (och HUD?)
        for (Sprite *sprite : added)
            sprites.push_back(sprite);   
        added.clear();
       
        // Remove i en metod
        for (Sprite* sprite : removed_) {
            for (auto i = sprites.begin(); i != sprites.end();) {
                if (*i == sprite) {
                    i = sprites.erase(i);
                } else {
                    i++;
                }
            }
        }
        removed_.clear();       
        
        SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);

        // de olika draw i en eller flera metoder
        for (Sprite *sprite : sprites)
           sprite->draw();


        for(Player *player : players_){
            player->draw();
        }

        SDL_RenderPresent(syst_.getRenderer());
        // FPS delay
        /*
        int delay = next_tick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }*/

    } // End outer while
} // End run


void Session::addSprite(Sprite* sprite){
    added.push_back(sprite);
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

void Session::remove(Sprite* sprite){
    removed_.push_back(sprite);
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
Session ses(800, 600, "game", "./images/Background.jpg");
