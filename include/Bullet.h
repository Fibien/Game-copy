#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"
#include "Session.h"
#include <string>
#include <SDL2/SDL.h>
#include <memory>

class Bullet : public Sprite , public std::enable_shared_from_this<Bullet>{

    public:
    static std::shared_ptr<Bullet> getInstance(int, int, int, int, SDL_Texture*);
    ~Bullet();
    void draw();
    void tick();
    bool toBeRemoved() {return remove;}
    void getCollisionBehaviour();


    Bullet(int, int, int, int, SDL_Texture*);    
    protected:

    private:
    bool remove{false};

};

#endif