#include "System.h"
#include "Session.h"
#include "Constants.h"
#include <string>
#include "Player.h"



void testMethod(){

    Player* p = Player::getInstance(800,50,100,50, "./images/Player.png");

    if (p->getTexture() == nullptr)
        std::cout << "Null in main " << std::endl;
    // Test System ctr
    //System sys; // 🗸
    // System sys(800, 600); // 🗸
    //std::string default_path = (constants::gResPath + "/images/gul.bmp");
    //System sys(800, 600, "Game", default_path); // 🗸

    //Session ses(800, 600, "game", "./images/gul.bmp");
    Session ses(800, 600, "game", "./images/Background.jpg");
    ses.addPlayer(p);
    //ses.addPlayer
    ses.run();


}


int main(int argc, char** argv){

    testMethod();

    

    return 0;
}

