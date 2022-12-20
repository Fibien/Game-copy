#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <string>
#include <initializer_list>
#include <map>

class System{

    typedef std::pair<std::string, std::string> input_pair;

    public:
    System(int, int, std::string, std::string);
    ~System();
    SDL_Renderer* getRenderer() {return ren_;}; 
    SDL_Texture* getBackgroundTexture() {return txt_;};
    void createTexture(std::initializer_list<input_pair> pairs);
    SDL_Texture* getTexture(std::string);
    void setWindow(int, int, SDL_Texture*);


    private:
    std::string title;
    int test = 0;
    // Ha kvar konstanterna?
    SDL_Window *window_;
    SDL_Renderer *ren_;
    SDL_Texture* txt_;
    std::map<std::string, SDL_Texture*> textures_;
};

#endif