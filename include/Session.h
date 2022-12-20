#ifndef SESSION_H
#define SESSION_H

#define DEFAULT_BACKGROUND "./images/Background.jpg"
#define DEFAULT_TITLE "Game"
#define DEFAULT_HEIGHT 800
#define DEFAULT_WIDTH 600

#include "Sprite.h"
#include "System.h"
#include "HUD.h"
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <string>
#include <functional>
#include <memory>
#include "Player.h"
#include "Bullet.h"


// Testa om dessa fortfarande behövs annars ta bort
//class Player;
//class Bullet;

class Session{

    typedef std::pair<std::string, std::string> input_pair;

    public:
    Session(int, int, std::string, std::string);
    void run();
    void addSprite(const std::shared_ptr<Sprite>&); 
    void addPlayer(std::shared_ptr<Player>);
    void addHUD(HUD*);
    void remove(const std::shared_ptr<Sprite>&); 
    void createTexture(std::initializer_list<input_pair> pairs);
    SDL_Texture* getTexture(std::string);
    SDL_Renderer* getRenderer();
    // Victory func
    // defeat func
    // collision  

    // void remove(Sprite&);
    // Add victory msgs
    // Add defeat msgs

    private:
    bool is_session_running_;
    int max_y_, max_x_;
    //void removeElement(std::vector<Sprite>&, Sprite);
    System syst_;

    std::vector<std::shared_ptr<Sprite> > sprites_;
    // Använda unique_ptr på player
    std::vector<std::shared_ptr<Player> > players_;
    std::vector<HUD*> HUDs_;
    std::vector<std::shared_ptr<Sprite> > added_;
    std::vector<std::shared_ptr<Sprite> > removed_;

};

extern Session ses;

#endif
