
#include "System.h"
#include "Constants.h"
#include <iostream>
#include <SDL2/SDL_image.h> 

using namespace constants;

System::System(int x, int y, std::string title, std::string path) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, x, y, 0);
    ren_ = SDL_CreateRenderer(window_, -1,0);
    std::cout << gResPath + path << std::endl;
    SDL_Texture *txt = IMG_LoadTexture(ren_, (gResPath + path).c_str());
    if (txt == nullptr)
        std::cout << "HALLO" << std::endl;
 
    //SDL_RenderCopy(ren_, txt, NULL, NULL);
    //SDL_RenderPresent(ren_);
}

System::~System(){
    std::cout << "System destructor invoked" << std::endl;
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(ren_);
    SDL_Quit();
}

const std::string System::default_background_ = "./images/Background.jpg";
const std::string System::default_title_ = "Game";
const int System::default_height_ = 800;
const int System::default_width_ = 600;

System syst_(800, 600, "Game", "./images/Background.jpg");

