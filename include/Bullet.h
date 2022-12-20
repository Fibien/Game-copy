#ifndef BULLET_H
#define BULLET_H

// Only use include directives that are neccessary for the .h file 
// Set the rest of the include directives in the .cpp file to
// minimize compile time. 
#include "Session.h"

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