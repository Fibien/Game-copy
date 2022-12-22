#include <memory>
#include <vector>
#include <string>
#include "Player.h"
#include "Bullet.h"
#include "HUD.h"
#include "Enemy.h"
#include <iostream>

void Player::tick(){
    std::vector<std::shared_ptr<Sprite> > sprites = ses.getSpriteVec();
    bool noMoreEnemies = true;
    for (auto sprite : sprites) {
        
        if (std::dynamic_pointer_cast<Enemy>(sprite)) {
            noMoreEnemies = false;
        }
    }

    // When there are no more enemies, player wins.
    if(noMoreEnemies){
        ses.winTheGame();
    }
} 

void Player::getCollisionBehaviour() {
    std::shared_ptr<HUD> hud = ses.getHUD();
    hud->decreaseLife();
    
    if(hud->getRemaningLives() == 0) {
        std::cerr << "Game ending" << std::endl;
        ses.looseTheGame();
    }
    hud->update();
}