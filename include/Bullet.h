#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"
#include <string>

class Bullet : public Sprite{

    public:
    static Bullet* getInstance(int, int, int, int, std::string);
    ~Bullet();
    void draw();
    void tick();

    protected:
    Bullet(int, int, int, int, std::string);    

    private:

};

#endif