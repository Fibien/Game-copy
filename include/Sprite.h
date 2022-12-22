#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>

class Sprite{

    public:
    virtual ~Sprite();
    bool hasCollided(const SDL_Rect*, const SDL_Rect*);
    void draw();

    virtual void tick() = 0;
    virtual void getCollisionBehaviour() {}

    SDL_Rect& getRect() { return rect_; }
    SDL_Texture* getTexture() const { return texture_; };

    bool operator==(const Sprite&);
 
    protected:
    Sprite(int, int, int, int, std::string);
    
    private:
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    SDL_Rect rect_;
    SDL_Texture* texture_;  
};

#endif