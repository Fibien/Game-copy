#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <map>
#include <SDL2/SDL.h>

class System{

    typedef std::pair<std::string, std::string> input_pair;

    public:
    System(int, int, std::string, std::string);
    ~System();
    void createTexture(std::initializer_list<input_pair> pairs);
    SDL_Renderer* getRenderer() {return ren_;}; 
    SDL_Texture* getBackgroundTexture() {return txt_;};
    SDL_Texture* getTexture(std::string);
    void setWindow(int, int, SDL_Texture*);
    int getMaxX() {return max_x_;}
    int getMaxY() {return max_y_;}

    private:
    SDL_Window *window_;
    SDL_Renderer *ren_;
    SDL_Texture* txt_;
    std::map<std::string, SDL_Texture*> textures_;
    int max_y_, max_x_;
    
};

#endif