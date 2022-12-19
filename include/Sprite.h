#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Constants.h"

class Sprite{

    public:
    
    virtual ~Sprite() {std::cout << "Sprite destructor" << std::endl; SDL_DestroyTexture(texture_);};
    virtual void draw(SDL_Renderer*) = 0;
    // virtual void tick(Session*) = 0;
    SDL_Rect& getRect() { return rect_; }
    bool isRemovable() const { return is_removable_;}
    SDL_Texture* getTexture() const { return texture_; };

    protected:
    Sprite(int, int, int, int, SDL_Texture*);
    
    private:
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    bool is_removable_;
    SDL_Rect rect_;
    SDL_Texture *texture_;
    
};

#endif