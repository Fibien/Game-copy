#ifndef SESSION_H
#define SESSION_H

#define DEFAULT_BACKGROUND "./images/Default_background.jpg"
#define DEFAULT_TITLE "Game"
#define DEFAULT_HEIGHT 800
#define DEFAULT_WIDTH 600

#include <vector>
#include <memory>
#include <SDL2/SDL_ttf.h>
#include "HUD.h"
#include "System.h"
#include "Player.h"

class HUD;

class Session{

    typedef std::pair<std::string, std::string> input_pair;
    typedef std::vector<std::shared_ptr<Sprite>>::const_iterator constSpriteIter;

    public:
    Session(int, int, std::string, std::string);
    ~Session();
    void run();
    void addSprite(const std::shared_ptr<Sprite>&); 
    void addPlayer(std::shared_ptr<Player>);
    void addHUD(std::shared_ptr<HUD>);
    void createTexture(std::initializer_list<input_pair> pairs);
    SDL_Texture* getTexture(std::string);
    SDL_Renderer* getRenderer(); 
    void remove(const std::shared_ptr<Sprite>&); 
    void setWindow(int, int, std::string);
    const std::vector<std::shared_ptr<Sprite>> getSpriteVec() const;
    int getMaxY() {return syst_.getMaxY();}
    std::shared_ptr<HUD> getHUD() const;    
    void decreaseLife();
    int getRemaingLives();
    void updateHUD();
    
    void setDefeatMessage(std::string, std::string, int);
    void setVictoryMessage(std::string, std::string, int);

    // setEndGamePath bool flags if the game was won or lost
    void winTheGame();
    void looseTheGame();

    private:
    void defeat();
    void victory();
    void setEndGamePath(bool);
    void setTextMessage(std::string, std::string, int);
    void displayPostScreen(std::string, std::string, int);
    void handleEvent(SDL_Event&);
    void clearRenderer();
    void handleTick();
    void handleCreatedElements();
    void handleCollision();
    void handleSpriteCollision();
    void handlePlayerCollision();
    void removeElements();
    void renderBackground();
    void invokeDrawOnElements();
    void displayElements();
    int determineDelay(Uint32);
    void createDelay(int);
   
   
    System syst_;
    bool is_session_running_;
    
    bool victory_ = false;
    bool userEndedSession_ = false;
    std::string victory_path_ = "./images/fonts/consola.ttf";
    std::string victory_messsage_ = "YOU WON!";
    int victory_text_size_ = 40;
    std::string defeat_path_ = "./images/fonts/consola.ttf";
    std::string defeat_messsage_ = "YOU LOST!";
    int defeat_text_size_ = 40;
    int shoot_timer_ = 0;
    int shoot_timer_limit = 30;

    TTF_Font* font_;

    std::vector<std::shared_ptr<Sprite> > sprites_;
    std::shared_ptr<Player> player_;
    std::shared_ptr<HUD> hud_;
    std::vector<std::shared_ptr<Sprite> > added_;
    std::vector<std::shared_ptr<Sprite> > removed_;
};

extern Session ses;

#endif