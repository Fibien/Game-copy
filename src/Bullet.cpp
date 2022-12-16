#include "Bullet.h"
#include <string.h>

Bullet::Bullet(int x, int y, int height, int width, std::string path) : Sprite(x,y,height,width,path){}

Bullet* Bullet::getInstance(int x, int y, int height, int width, std::string path){
    return new Bullet(x,y,height,width,path);
}