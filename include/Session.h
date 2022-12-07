#ifndef SESSION_H
#define SESSION_H

#include "Sprite.h"
#include "System.h"
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

class Session{

    public:

    Session(int, int, std::string, std::string);
    //Session(std::unordered_map<SDL_Event,int> test );
    void run();
    void add(Sprite&);
    void remove(Sprite&);
    // Add victory msgs
    // Add defeat msgs

    private:
    
    void removeElement(std::vector<Sprite>&, Sprite);
    System sys_;
    // Deklarera en samling för objekt som ska läggas till och för objekt som tag bort
    std::vector<Sprite> sprite_;

};


#endif
