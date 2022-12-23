#include <memory>
#include <string>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

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
  
    ses.decreaseLife();

    if(ses.getRemaingLives() == 0){
        ses.looseTheGame();
    }
    ses.updateHUD();
}