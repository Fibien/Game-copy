#ifndef SESSION_H
#define SESSION_H

#define DEFAULT_BACKGROUND "./images/Default_background.jpg"
#define DEFAULT_TITLE "Game"
#define DEFAULT_HEIGHT 800
#define DEFAULT_WIDTH 600

#include <vector>
#include <memory>
#include "HUD.h"
#include "System.h"
#include "Player.h"

class Session{

    typedef std::pair<std::string, std::string> input_pair;
    typedef std::vector<std::shared_ptr<Sprite>>::const_iterator constSpriteIter;

    public:
    Session(int, int, std::string, std::string);
    void run();
    void addSprite(const std::shared_ptr<Sprite>&); 
    void addPlayer(std::shared_ptr<Player>);
    void addHUD(HUD*);
    void createTexture(std::initializer_list<input_pair> pairs);
    SDL_Texture* getTexture(std::string);
    SDL_Renderer* getRenderer(); 
    void remove(const std::shared_ptr<Sprite>&); 
    void setWindow(int, int, SDL_Texture*);
    int getMaxY() {return syst_.getMaxY();}
    const std::vector<std::shared_ptr<Sprite>> getSpriteVec() const;
    
    // Victory func
    // defeat func
    // collision  

    // void remove(Sprite&);
    // Add victory msgs
    // Add defeat msgs

    private:
    void handleEvent(SDL_Event&);
    void clearRenderer();
    void handleTick();
    void handleCreatedElements();
    void handleCollision();
    void removeElements();
    void renderBackground();
    void invokeDrawOnElements();
    void displayElements();
    int determineDelay(Uint32);
    void createDelay(int);
    System syst_;
    bool is_session_running_;
   
    //int max_y_, max_x_;

    std::vector<std::shared_ptr<Sprite> > sprites_;
    // Använda unique_ptr på player ??
    std::vector<std::shared_ptr<Player> > players_;
    std::vector<HUD*> HUDs_;
    std::vector<std::shared_ptr<Sprite> > added_;
    std::vector<std::shared_ptr<Sprite> > removed_;

};

extern Session ses;

#endif
