#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Constants.h"

class Sprite{

    public:
    
    // Korrekt, destruktorn i bas-/superklass kommer anropas så småningom, lägg till att resurserna i Sprite destrueras där.   
    // https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks/
    virtual ~Sprite() {std::cout << "Sprite destructor" << std::endl;};
    virtual void draw() = 0;
    virtual void tick() = 0;
    virtual void getCollisionBehaviour() {  }
    SDL_Rect& getRect() { return rect_; }
    SDL_Texture* getTexture() const { return texture_; };
    bool hasCollided(const SDL_Rect*, const SDL_Rect*);
    bool operator==(const Sprite&);
    

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