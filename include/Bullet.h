#ifndef BULLET_H
#define BULLET_H

// Only use include directives that are neccessary for the .h file 
// Set the rest of the include directives in the .cpp file to
// minimize compile time. 
#include "Session.h"

class Bullet : public Sprite , public std::enable_shared_from_this<Bullet>{

    public:
    ~Bullet();
    static std::shared_ptr<Bullet> getInstance(int, int, int, int, SDL_Texture*);
    void draw();
    void tick();
    bool toBeRemoved() {return remove;}
    void getCollisionBehaviour();

    protected:
    // Ctr moved from public to protected
    Bullet(int, int, int, int, SDL_Texture*);  

    private:
    // Ha kvar?
    bool remove{false};

};

#endif