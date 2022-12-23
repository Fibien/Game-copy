#include "Game.h"

int main(int argc, char** argv){

    Game* game = Game::getInstance();
    game->run();
    delete game;

    return 0;
}