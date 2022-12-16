#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <string>

class System{

    public:
    // Fundera på dessa, ta bort eller ha kvar?
    System();
    System(int, int);
    System(int, int, std::string, std::string);
    ~System();
    SDL_Renderer* getRenderer() {return ren_;}; 
    SDL_Texture* getTexture() {return txt_;};

    private:
    const static std::string default_background_;
    const static std::string default_title_;
    const static int default_height_;
    const static int default_width_;
    SDL_Window *window_;
    SDL_Renderer *ren_;
    SDL_Texture* txt_;
};

extern System syst_;

#endif