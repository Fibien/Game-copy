#include "System.h"
#include "Session.h"
#include "Constants.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <memory>

typedef std::pair<std::string, std::string> input_pair;

void testMethod(){

    input_pair player = std::make_pair("Player", "./images/Player.png");


    input_pair bullet = std::make_pair("Bullet", "./images/Bullet.png");
    input_pair enemy = std::make_pair("Enemy", "./images/Enemy.png");

    // Test System ctr
    //System sys; // 🗸
    // System sys(800, 600); // 🗸
    //std::string default_path = (constants::gResPath + "/images/gul.bmp");
    //System sys(800, 600, "Game", default_path); // 🗸

    //Session ses(800, 600, "game", "./images/gul.bmp");
    //Session ses(800, 600, "game", "./images/gul.bmp");
    ses.createTexture({player, bullet, enemy});
    std::shared_ptr<Player> ptr = Player::getInstance(100,500,100,100, ses.getTexture("Player"));
    std::shared_ptr<Sprite> eptr = Enemy::getInstance(100, 0, 100, 100, ses.getTexture("Enemy"));

    //if (p->getTexture() == nullptr)
    //    std::cout << "Null in main " << std::endl;
    ses.addSprite(eptr);
    ses.addPlayer(ptr);
    //ses.addPlayer
    ses.run();

}


int main(int argc, char** argv){

    testMethod();

    

    return 0;
}

