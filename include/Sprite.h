#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class Sprite{

    public:
    
    virtual ~Sprite() {};
    virtual void draw() const = 0;
    virtual void tick() = 0;
    SDL_Rect getRect() const { return rect; }
    bool isRemovable() const;
    

    protected:
    Sprite(int, int, int, int, std::string);
    Sprite();

    private:
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    SDL_Rect rect;
    



};

#endif