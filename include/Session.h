#ifndef SESSION_H
#define SESSION_H

#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include "HUD.h"
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

class Session{

    public:

    Session(int, int, std::string, std::string);
    //Session(std::unordered_map<SDL_Event,int> test );
    void run();
    void addSprite(Sprite*);
    void addPlayer(Player*);
    void addHUD(HUD*);
    void remove(Sprite*);

    // Victory func
    // defeat func
    // collision  

    void remove(Sprite&);
    // Add victory msgs
    // Add defeat msgs

    private:
    bool is_session_running_;
    //void removeElement(std::vector<Sprite>&, Sprite);
    // System sys_;
    // Deklarera en samling för objekt som ska läggas till och för objekt som tag bort

    std::vector<Sprite*> sprites;
    std::vector<Player*> players_;
    std::vector<HUD*> HUDs_;
    std::vector<Sprite*> added;
    std::vector<Sprite*> removed;
    
   
};


#endif
