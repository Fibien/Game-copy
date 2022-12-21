// Ta bort iostream efter testning
#include <iostream>
#include <SDL2/SDL_image.h> 
#include "System.h"
#include "Constants.h"

using namespace constants;

System::System(int x, int y, std::string title, std::string path) {
    max_x_ = x;
    max_y_ = y;

    SDL_Init(SDL_INIT_EVERYTHING);
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, x, y, 0);
    ren_ = SDL_CreateRenderer(window_, -1,0);
    txt_ = IMG_LoadTexture(ren_, (gResPath + path).c_str());
    SDL_RenderCopy(ren_, txt_, NULL, NULL);
    SDL_RenderPresent(ren_);
}

System::~System(){
    std::cout << "System destructor invoked" << std::endl;
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(ren_);
    SDL_Quit();
}

void System::createTexture(std::initializer_list<input_pair> pairs){

    for(input_pair pair : pairs){
    
        SDL_Texture* image = IMG_LoadTexture(ren_, (constants::gResPath + pair.second).c_str());
        if(image == nullptr){
            std::cout << "Image was not found" << std::endl;
        }else{
            textures_.insert(std::make_pair(pair.first, image));
        }
    }
}
    
SDL_Texture* System::getTexture(std::string key) {
    return textures_.at(key);
}

void System::setWindow(int x, int y, SDL_Texture* txt_){
    this->txt_ = txt_;
    max_x_ = x;
    max_y_ = y;
    SDL_SetWindowSize(window_, x, y);
    SDL_RenderClear(ren_);
    SDL_RenderCopy(ren_, txt_, NULL, NULL);
    SDL_RenderPresent(ren_);
}

