﻿#define FPS 60
#include <Session.h>

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

                case SDL_QUIT: quit = true; break;
                // SDL_KEYDOWN 
                // Anropar Player via dess pekare (Player ligger i Sprite samlingen)
                // Player anropar den tänkta knappe, övriga sprites anropas ej

                // SDL_Keydown, samma för player anropar skjutfunktionen i player    
            
            }
        
        }

         // Tick för sprites

        // Lägga till element (och HUD?)

        // Ta bort element (och HUD?)

        // Draw, ritar ut alla objekt, obs på HUD och sprite samling

        // FPS delay
        //if(delay > 0){
        // fortsätt vänta
        //}    
    
    }





}

void Session::add(Sprite& sprite){
    // Ändra till added vectorn, minskar kodduplicering. 
    sprite_.push_back(sprite);
}

void Session::remove(Sprite& sprite){
    // Tänk mer, interaktion med remove vektorn?
    //vec.erase();
}

// TODO Later
void Session::removeElement(std::vector<Sprite>& vec, Sprite sprite){
    for(std::vector<Sprite>::iterator i = vec.begin(); i != vec.end();){

    }
}