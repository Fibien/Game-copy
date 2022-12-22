#ifndef HUD_H
#define HUD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class HUD{

    public:
    virtual ~HUD();
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void increasePoints() = 0;
    virtual void decreaseLife() = 0;
    void setText(std::string, int, std::string);
    void setPointsPerHit(int);
    void setLives(int);
    void setDamageTakenPerHit(int);
    int getRemaningLives() {return lives;}
    int getTotalPoints() {return totalPoints;}
   
    
    SDL_Texture* getTexture();
    SDL_Rect& getRect();
    
    protected:
    HUD(int x, int y, int w, int h, SDL_Texture* txt, std::string path, int size, int points = 10, int lives = 3, int multiplier = 1) : rect_{x, y, w, h}, path(path), size(size), pointsPerHit(points), lives(lives), multiplier(multiplier), textTexture(txt) { };
    SDL_Rect rect_;
    std::string path;
    int size;
    int pointsPerHit;
    int lives;
    int multiplier;
    int totalPoints{0};
    std::string text_;
    
    private:
    HUD(const HUD&) = delete;
    const HUD& operator=(const HUD&) = delete;
    SDL_Texture* textTexture;
    TTF_Font* font;
    

};

#endif