#include "System.h"
#include "Session.h"
#include "Constants.h"
#include <string>
#include "Player.h"

typedef std::pair<std::string, std::string> input_pair;

void testMethod(){

    input_pair player = std::make_pair("Player", "./images/Player.png");


    input_pair bullet = std::make_pair("Bullet", "./images/Bullet.png");
    // Test System ctr
    //System sys; // 🗸
    // System sys(800, 600); // 🗸
    //std::string default_path = (constants::gResPath + "/images/gul.bmp");
    //System sys(800, 600, "Game", default_path); // 🗸

    //Session ses(800, 600, "game", "./images/gul.bmp");
    //Session ses(800, 600, "game", "./images/gul.bmp");
    ses.createTexture({player, bullet});
    Player* p = Player::getInstance(100,500,100,100, ses.getTexture("Player"));

    //if (p->getTexture() == nullptr)
    //    std::cout << "Null in main " << std::endl;
    ses.addPlayer(p);
    //ses.addPlayer
    ses.run();

    delete p;
}


int main(int argc, char** argv){

    testMethod();

    

    return 0;
}

