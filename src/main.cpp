#include "System.h"
#include "Session.h"
#include <Constants.h>
#include <string>



void testMethod(){

    std::string default_path = (constants::gResPath + "/images/gul.bmp");

    // Test System ctr
    // System sys; // 🗸
    // System sys(800, 600); // 🗸
    //System sys(800, 600, "Game", default_path); // 🗸

    Session ses(800, 600, "game", "./resources/images/gul.bmp");
    ses.run();


}


int main(int argc, char** argv){

    testMethod();

    return 0;
}

