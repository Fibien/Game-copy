
#include "Session.h"
#include "Player.h"
#include "Enemy.h"

typedef std::pair<std::string, std::string> input_pair;

void createTextures(){
    input_pair background = std::make_pair("Background", "./images/Player2.png");
    input_pair player = std::make_pair("Player", "./images/Player.png");
    input_pair bullet = std::make_pair("Bullet", "./images/Bullet.png");
    input_pair enemy = std::make_pair("Enemy", "./images/Enemy.png");
    ses.createTexture({background, player, bullet, enemy});
}

void setWindow(){
    ses.setWindow(1200, 900, ses.getTexture("Background"));
}

void addEntities(){

    std::shared_ptr<Player> ptr = Player::getInstance(100,500,100,100, ses.getTexture("Player"));
    std::shared_ptr<Sprite> eptr = Enemy::getInstance(100, 0, 100, 100, ses.getTexture("Enemy"));
    ses.addSprite(eptr);
    ses.addPlayer(ptr);
}

void createSession(){

    createTextures();
    setWindow();
    addEntities();
    ses.run();
}


int main(int argc, char** argv){

    createSession();

    return 0;
}

