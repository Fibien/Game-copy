#include "System.h"
#include "Constants.h"
#include <iostream>
#include <SDL2/SDL_image.h> 

using namespace constants;



System::System(){
    System(default_height_, default_width_, default_title_, default_path_);
}

System::System(int x, int y){
    System(x, y, default_title_, default_path_);
}

System::System(int x, int y, std::string title, std::string path){
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, x, y, 0);
    ren_ = SDL_CreateRenderer(window_, -1,0);
    //SDL_Surface *surf = SDL_LoadBMP(path.c_str());
    //SDL_Texture *txt = SDL_CreateTextureFromSurface(ren_, surf);
    SDL_Texture *txt = IMG_LoadTexture(ren_, (gResPath + "/images/bg.jpg").c_str());
    SDL_RenderCopy(ren_, txt, NULL, NULL);
    //SDL_FreeSurface(surf);
    SDL_RenderPresent(ren_);
}

System::~System(){
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(ren_);
    SDL_Quit();
}

SDL_Renderer* System::getRenderer(){
    return ren_;
}

const std::string System::default_path_ = gResPath + "/images/gul.bmp";
const std::string System::default_title_ = "Game";
const int System::default_height_ = 800;
const int System::default_width_ = 600;

