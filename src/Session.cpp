#define FPS 60
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
            
                case SDL_QUIT: quit = true;
            
            
            
            }
        
        
        
        }


    
    
    }





}

void Session::add(Sprite& sprite){
    vec_.push_back(sprite);
}

void Session::remove(Sprite& sprite){
    //vec.erase();
}

// TODO Later
void Session::removeElement(std::vector<Sprite>& vec, Sprite sprite){
    for(std::vector<Sprite>::iterator i = vec.begin(); i != vec.end();){

    }
}