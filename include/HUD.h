#ifndef HUD_H
#define HUD_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Session.h"

class Session;

class HUD{

    public:
    virtual ~HUD();
    virtual void draw();
    virtual void update() = 0;
    virtual void increasePoints() = 0;
    virtual void decreaseLife() = 0;
    int getRemaningLives() const {return lives_;}
    int getTotalPoints() const {return total_points_;}
   
    SDL_Texture* getTexture();
    SDL_Rect& getRect();
    
    protected:
    void setText(std::string, int, std::string);
    HUD(int, int, int, int, std::string, std::string, int, int, int, int);
    void addToTotalPoints(int);
    int getPointsPerHit() {return pointsPerHit_;}    
    void subtractFromLives(int);
    int getDamageMultiplier() {return damage_multiplier_;}
    int getSize() {return size_;}
    std::string getPath() {return path_;}

    private:
    HUD(const HUD&) = delete;
    const HUD& operator=(const HUD&) = delete;

    SDL_Rect rect_;
    SDL_Texture* text_texture_;
    TTF_Font* font_;

    std::string path_;
    int size_;
    int pointsPerHit_;
    int lives_;
    int damage_multiplier_;
    int total_points_{0};
   

    
};

#endif