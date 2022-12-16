#include "Session.h"
#include "Sprite.h"
#include <algorithm>
#include "Player.h"
#define FPS 60
//#include "Pl"

// Skapa default varianter, flytta konstanter från system
Session::Session(int x, int y, std::string name, std::string path) : sys_(x,y,name, path){}

void Session::run(){

    bool quit = false;
    Uint32 tick_interval = 1000 / FPS;
    while(!quit){
    
        Uint32 next_tick = SDL_GetTicks() + tick_interval;
        SDL_Event event;
        while(SDL_PollEvent(&event)){
        
            switch(event.type){
            
                // Lägga till paus func senare
                case SDL_KEYUP: {
                    //for_each(players_.begin(), players_.end(), [&event](Sprite& sprite)->void{sprite.keyDown(event);});                 
                    // itererar igenom lista och anropar keyup på varje element
                break;
                }
                case SDL_KEYDOWN: {
                      //  for_each(players_.begin(), players_.end(), [&event](Sprite& sprite)->void{sprite.keyUp(event);});
                        //for(int i = players_.begin(); i != players_.end(); i++){
                        //}
                         // itererar igenom lista och anropar keydown på varje element
                break;
                }
                case SDL_QUIT: quit = true; break;
                // SDL_KEYDOWN 
                // Anropar Player via dess pekare (Player ligger i Sprite samlingen)
                // Player anropar den tänkta knappe, övriga sprites anropas ej

                // SDL_Keydown, samma för player anropar skjutfunktionen i player    
            
            }
        
        }

         // Tick för sprites
        //for (auto sprite : sprites) 
          //  sprite.tick();
        // Lägga till element (och HUD?)

        // Ta bort element (och HUD?)

        // Draw, ritar ut alla objekt, obs på HUD och sprite samling

        // FPS delay
        int delay = next_tick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }
    } // outer while
}

void Session::addSprite(Sprite& sprite){
    // Ändra till added vectorn, minskar kodduplicering. 
    added.push_back(sprite);
}

// Kolla om de pekar på samma obj
void Session::addPlayer(Sprite *player){
    players_.push_back(player);
    addSprite(*player);
}


void Session::remove(Sprite& sprite){
    // Tänk mer, interaktion med remove vektorn?
    //vec.erase();
}

// TODO Later
/*
void Session::removeElement(std::vector<Sprite>& vec, Sprite sprite){
    for(std::vector<Sprite>::iterator i = vec.begin(); i != vec.end();){

    } 
} */