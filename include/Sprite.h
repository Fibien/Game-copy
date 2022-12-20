#ifndef SPRITE_H
#define SPRITE_H

// Ta bort iostream efter testning
#include <iostream>
#include <SDL2/SDL.h>

class Sprite{

    public:
    
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
    SDL_Rect rect_;
    SDL_Texture *texture_;
    
};

#endif