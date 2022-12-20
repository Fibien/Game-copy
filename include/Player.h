#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite{

    public:
    static std::shared_ptr<Player> getInstance(int, int, int, int, SDL_Texture*);
    void draw();
    void keyDown(SDL_Event&, int);
    void keyUp(SDL_Event&, int);
    void tick();
    ~Player();

    protected:
    // Ctr moved from public to protected
    Player(int x, int y, int height, int width, SDL_Texture* texture) : Sprite(x, y, height, width, texture) {}

};



#endif