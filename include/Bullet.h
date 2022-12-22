#ifndef BULLET_H
#define BULLET_H

#include "Session.h"

class Bullet : public Sprite , public std::enable_shared_from_this<Bullet>{

    public:
    ~Bullet() {};
    static std::shared_ptr<Bullet> getInstance(int, int, int, int, std::string, bool);
    void getCollisionBehaviour();
    void tick();
   
    protected:
    Bullet(int, int, int, int, std::string, bool);  

    private:
    bool shot_from_player_;
};

#endif