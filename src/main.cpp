
#include "Session.h"
#include "Player.h"
#include "Enemy.h"

typedef std::pair<std::string, std::string> input_pair;

void createTextures(){
    input_pair background = std::make_pair("Background", "./images/Background.jpg");
    input_pair player = std::make_pair("Player", "./images/Player.png");
    input_pair bullet = std::make_pair("Bullet", "./images/Bullet.png");
    input_pair enemy = std::make_pair("Enemy", "./images/Enemy.png");
    ses.createTexture({background, player, bullet, enemy});
}

void setWindow(){
    ses.setWindow(1000, 700, ses.getTexture("Background"));
}

void addEntities(){

    int ewidth = 40;
    int eheight = 46;
    int xstartpos = 80;
    int xoffset = 100;
    int ystartpos = 0;
    int yoffset = 56;
    
    // Create Player

    std::shared_ptr<Player> ptr = Player::getInstance(100,580,100,100, ses.getTexture("Player"));

    // Add Player
    ses.addPlayer(ptr);

    // Create Enemies

    // First row
    std::shared_ptr<Sprite> eptr1 = Enemy::getInstance(xstartpos, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2 = Enemy::getInstance(xstartpos + xoffset, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3 = Enemy::getInstance(xstartpos + xoffset * 2, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr4 = Enemy::getInstance(xstartpos + xoffset * 3, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr5 = Enemy::getInstance(xstartpos + xoffset * 4, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr6 = Enemy::getInstance(xstartpos + xoffset * 5, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr7 = Enemy::getInstance(xstartpos + xoffset * 6, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr8 = Enemy::getInstance(xstartpos + xoffset * 7, ystartpos, ewidth, eheight, ses.getTexture("Enemy"));

    // // Second row
    std::shared_ptr<Sprite> eptr2e1 = Enemy::getInstance(xstartpos, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e2 = Enemy::getInstance(xstartpos + xoffset * 1, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e3 = Enemy::getInstance(xstartpos + xoffset * 2, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e4 = Enemy::getInstance(xstartpos + xoffset * 3, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e5 = Enemy::getInstance(xstartpos + xoffset * 4, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e6 = Enemy::getInstance(xstartpos + xoffset * 5, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e7 = Enemy::getInstance(xstartpos + xoffset * 6, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr2e8 = Enemy::getInstance(xstartpos + xoffset * 7, ystartpos + yoffset, ewidth, eheight, ses.getTexture("Enemy"));
  

    // // Third row
    std::shared_ptr<Sprite> eptr3e1 = Enemy::getInstance(xstartpos, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e2 = Enemy::getInstance(xstartpos + xoffset * 1, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e3 = Enemy::getInstance(xstartpos + xoffset * 2, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e4 = Enemy::getInstance(xstartpos + xoffset * 3, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e5 = Enemy::getInstance(xstartpos + xoffset * 4, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e6 = Enemy::getInstance(xstartpos + xoffset * 5, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e7 = Enemy::getInstance(xstartpos + xoffset * 6, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    std::shared_ptr<Sprite> eptr3e8 = Enemy::getInstance(xstartpos + xoffset * 7, ystartpos + yoffset * 2, ewidth, eheight, ses.getTexture("Enemy"));
    
   
    // A
    // ----Enemies----
    // row 1
    ses.addSprite(eptr1);
    ses.addSprite(eptr2);
    ses.addSprite(eptr3);
    ses.addSprite(eptr4);
    ses.addSprite(eptr5);
    ses.addSprite(eptr6);
    ses.addSprite(eptr7);
    ses.addSprite(eptr8);

    // row 2
    ses.addSprite(eptr2e1);
    ses.addSprite(eptr2e2);
    ses.addSprite(eptr2e3);
    ses.addSprite(eptr2e4);
    ses.addSprite(eptr2e5);
    ses.addSprite(eptr2e6);
    ses.addSprite(eptr2e7);
    ses.addSprite(eptr2e8);
    
    // row 3
    ses.addSprite(eptr3e1);
    ses.addSprite(eptr3e2);
    ses.addSprite(eptr3e3);
    ses.addSprite(eptr3e4);
    ses.addSprite(eptr3e5);
    ses.addSprite(eptr3e6);
    ses.addSprite(eptr3e7);
    ses.addSprite(eptr3e8);

 
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

