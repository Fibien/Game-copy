#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <string>

class System{

    public:
    System();
    System(int, int);
    System(int, int, std::string, std::string);
    ~System();
    SDL_Renderer* getRenderer(); 

    private:
    //static const std::string defaultPath;
    SDL_Window *window;
    SDL_Renderer *ren;
};


#endif