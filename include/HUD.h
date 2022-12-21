#ifndef HUD_H
#define HUD_H

#include <SDL2/SDL.h>
#include <string>

class HUD{

    public:
    virtual ~HUD();
    virtual void draw() = 0;
    virtual void setText(std::string, int, std::string) = 0;
    virtual void increasePoints() = 0;
    virtual void decreaseLife() = 0;
    void setPointsPerHit(int);
    void setLives(int);
    void setDamageTakenPerHit(int);
    int getRemaningLives() {return lives;}
   
    
    SDL_Texture* getTexture();
    SDL_Rect& getRect();
    
    protected:
    HUD(int x, int y, int w, int h, SDL_Texture* txt, int points = 10, int lives = 3, int multiplier = 1) : rect_{x, y, w, h}, pointsPerHit(points), lives(lives), multiplier(multiplier), tex_(txt) { };
    SDL_Rect rect_;
    int pointsPerHit;
    int lives;
    int multiplier;
    int totalPoints{0};
    
    private:
    HUD(const HUD&) = delete;
    const HUD& operator=(const HUD&) = delete;
    SDL_Texture* tex_;
    SDL_Texture* textTexture;
    

};

#endif