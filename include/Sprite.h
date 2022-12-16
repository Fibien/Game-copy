#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Sprite{

    public:
    
    virtual ~Sprite() {std::cout << "Sprite destructor" << std::endl; SDL_DestroyTexture(texture_);};
    virtual void draw() const = 0;
    virtual void tick() = 0;
    SDL_Rect* getRect() const { return rect_; }
    bool isRemovable() const { return is_removable_;}
    SDL_Texture* getTexture() const { return texture_; };

    protected:
    Sprite(int, int, int, int, std::string);

    private:
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    bool is_removable_;
    SDL_Rect* rect_;
    SDL_Texture* texture_;
    int x, y, width, height;
    
};

#endif