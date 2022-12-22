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
#include <SDL2/SDL_ttf.h>

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
    void setWindow(int, int, SDL_Texture*);
    int getMaxY() {return syst_.getMaxY();}
    void setVictoryMessage(std::string, std::string, int);
    void setDefeatMessage(std::string, std::string, int);
    void defeat();
    void victory();
    void endRun(bool);

    const std::vector<std::shared_ptr<Sprite>> getSpriteVec() const;
    std::shared_ptr<HUD> getHUD();    

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
    void setTextMessage(std::string, std::string, int);

    System syst_;
    bool is_session_running_;
    bool victory_ = false;
    bool userEndedSession = false;
    std::string victory_path = "./images/fonts/consola.ttf";
    std::string victory_messsage = "YOU WON!";
    int victory_text_size = 40;
    std::string defeat_path = "./images/fonts/consola.ttf";
    std::string defeat_messsage = "YOU LOST!";
    int defeat_text_size = 40;

    // Ta bort??
    SDL_Texture* test;
    SDL_Rect testRect;


    TTF_Font* font_;

    std::vector<std::shared_ptr<Sprite> > sprites_;
    // Använda unique_ptr på player ??
    std::vector<std::shared_ptr<Player> > players_;
    std::shared_ptr<HUD> hud_;
    std::vector<std::shared_ptr<Sprite> > added_;
    std::vector<std::shared_ptr<Sprite> > removed_;

};

extern Session ses;

#endif
