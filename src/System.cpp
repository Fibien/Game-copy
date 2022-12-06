#include "System.h"
#include "Constants.h"
#include <iostream>

using namespace constants;



System::System(){
    std::cout << "Initiera";
    System(800, 600);
}

System::System(int x, int y){
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, x, y, 0);
    ren = SDL_CreateRenderer(window, -1,0);
    std::string path = (gResPath + "images/gul.bmp");
    std::cout << path << std::endl;
    SDL_Surface *surf = SDL_LoadBMP(path.c_str());
    SDL_Texture *txt = SDL_CreateTextureFromSurface(ren, surf);
    SDL_RenderCopy(ren, txt, NULL, NULL);
    SDL_FreeSurface(surf); 
    SDL_RenderPresent(ren);
    SDL_Delay(1000000);
}

System::System(int x, int y, std::string title, std::string path){
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, x, y, 0);
    ren = SDL_CreateRenderer(window, -1,0);
    SDL_Delay(1000);
    SDL_Surface *surf = SDL_LoadBMP(path.c_str());
    SDL_Texture *txt = SDL_CreateTextureFromSurface(ren, surf);
    SDL_RenderCopy(ren, txt, NULL, NULL);
    SDL_FreeSurface(surf);
    SDL_RenderPresent(ren);
}

System::~System(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

SDL_Renderer* System::getRenderer(){
    return ren;
}

//const std::string defaultPath = gResPath + "gul.bmp";

