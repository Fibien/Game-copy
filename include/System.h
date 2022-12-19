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
    // Implementera en start metod som sätter upplösning och bakgrund alt gör en setResolution och setBackground metod

    private:
    const static std::string default_background_;
    const static std::string default_title_;
    const static int default_height_;
    const static int default_width_;
    SDL_Window *window_;
    SDL_Renderer *ren_;
    SDL_Texture* txt_;
    std::map<std::string, SDL_Texture*> textures_;
};

#endif