#ifndef HUD_H
#define HUD_H

#include <SDL2/SDL.h>
#include <string>

class HUD{

    public:
    virtual void draw() = 0;
    virtual void setText(std::string) = 0;
    protected:
    HUD(int, int, int, int);

    private:
    SDL_Rect rect_;

};

#endif