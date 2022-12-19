#include <algorithm>
#include <stdexcept>
#include "System.h"
#include "Session.h"
#include "Sprite.h"
#include "Player.h"
#define FPS 60
//#include "Pl"

// Skapa default varianter, flytta konstanter från system
Session::Session(int x, int y, std::string title, std::string path) : syst_(x, y, title, path){
    max_x_ = x;
    max_y_ = y;
}

void Session::run(){

    is_session_running_ = true;
    bool quit = false;
    Uint32 tick_interval = 1000 / FPS;
    while(!quit){
        // Uint32 next_tick = SDL_GetTicks() + tick_interval;
        SDL_Event event;
        while(SDL_PollEvent(&event)){
        
            switch(event.type){
            
                // Lägga till paus func senare
                case SDL_KEYUP: {
                break;
                }

                case SDL_KEYDOWN: {
                    for(Player *player : players_){
                        player->keyDown(event, max_x_, this); 
                    }   
                    break;
                }
                case SDL_QUIT: quit = true; break;
                // SDL_KEYDOWN 
                // Anropar Player via dess pekare (Player ligger i Sprite samlingen)
                // Player anropar den tänkta knappe, övriga sprites anropas ej

                // SDL_Keydown, samma för player anropar skjutfunktionen i player    
            
            } // switch
        
        } // inner while

        SDL_RenderClear(syst_.getRenderer());

        //  Tick för sprites
        for (Sprite *sprite : sprites) 
           sprite->tick();
        // // Lägga till element (och HUD?)
        for (Sprite *sprite : added)
            sprites.push_back(sprite);   
        added.clear();
        // Ta bort element (och HUD?)

        // Draw, ritar ut alla objekt, obs på HUD och sprite samling
      
        
        //for (Sprite *sprite : sprites)
          //  sprite->draw();

   

        // SDL_SetRenderDrawColor()
        SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);

        for (Sprite *sprite : sprites)
           sprite->draw(syst_.getRenderer());


        for(Player *player : players_){
            player->draw(syst_.getRenderer());
        }

        SDL_RenderPresent(syst_.getRenderer());
        // FPS delay
        /*
        int delay = next_tick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }*/

    } // End outer while
} // End run()


void Session::addSprite(Sprite* sprite){
    // Ändra till added vectorn, minskar kodduplicering. 
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

void Session::remove(Sprite& sprite){
    // Tänk mer, interaktion med remove vektorn?
    //vec.erase();
}

void Session::createTexture(std::initializer_list<input_pair> pairs){
    syst_.createTexture(pairs);
}

SDL_Texture* Session::getTexture(std::string key){
    return syst_.getTexture(key);
}


// TODO Later
/*
void Session::removeElement(std::vector<Sprite>& vec, Sprite sprite){
    for(std::vector<Sprite>::iterator i = vec.begin(); i != vec.end();){

    } 
} */

