#include "System.h"
#include "Session.h"

Session ses(800, 600, "game", "./resources/images/gul.bmp");

int main(int argc, char** argv){

    ses.run();

    return 0;
}