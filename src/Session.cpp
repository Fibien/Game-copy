
// Ta bort iostream efter testning
#include <iostream>
#include <memory>
#include <SDL2/SDL_ttf.h>
#include "Session.h"
#include "Constants.h"

#include <SDL2/SDL_image.h> 

#define FPS 60

// Typedef have captital letter for every word
typedef std::shared_ptr<Sprite> SpritePtr;
typedef std::shared_ptr<Player> PlayerPtr;
typedef std::shared_ptr<HUD> HUDptr;
typedef std::vector<std::shared_ptr<Sprite>>::iterator SpriteVectorIterator;
typedef long long unsigned int LongUInt;

using namespace constants;

Session::Session(int x, int y, std::string title, std::string path) : syst_(x, y, title, path){}

Session::~Session() {
}

void Session::run(){

    is_session_running_ = true;
    Uint32 tick_interval = 1000 / FPS;

    while(is_session_running_){

        Uint32 next_tick = SDL_GetTicks64() + tick_interval;
        SDL_Event event;

        handleEvent(event);

        clearRenderer();

        handleCreatedElements();
// swithced places 
        handleTick();

        handleCollision();

        removeElements();

        renderBackground();

        invokeDrawOnElements();

        displayElements();

        int delay = determineDelay(next_tick);
        createDelay(delay);

    } // End outer while
    if(!userEndedSession){
        victory_ ? victory() : defeat();
    }

    // Göra funktion för nedstägning av programmet 
    TTF_CloseFont(font_);
    TTF_Quit();
    SDL_Quit();    

} // End run

void Session::addSprite(const std::shared_ptr<Sprite>& sprite) {
    added_.push_back(std::move(sprite));
}

void Session::addPlayer(std::shared_ptr<Player> player){
    if(is_session_running_){
        throw std::invalid_argument("Players can't be added during runtime");
    }
    players_.push_back(player);
}

void Session::addHUD(std::shared_ptr<HUD> hud){
     if(is_session_running_){
        throw std::invalid_argument("HUDs can't be added during runtime");
    }
    hud_ = hud;
}

void Session::createTexture(std::initializer_list<input_pair> pairs){
    syst_.createTexture(pairs);
}

SDL_Texture* Session::getTexture(std::string key){
    return syst_.getTexture(key);
}

SDL_Renderer* Session::getRenderer() {
    return syst_.getRenderer();
}

void Session::remove(const std::shared_ptr<Sprite> &sprite) {
    removed_.push_back(std::move(sprite));
}

void Session::setWindow(int height, int width, SDL_Texture* texture) {
    syst_.setWindow(height, width, texture);
}

void Session::setDefeatMessage(std::string message, std::string path, int size){
     defeat_messsage = message;
     defeat_path = path;
     defeat_text_size = size;
}

void Session::setVictoryMessage(std::string message, std::string path, int size){
    victory_messsage = message;
    victory_path = path;
    victory_text_size = size;
}

void Session::defeat(){
    clearRenderer();

    setTextMessage(defeat_messsage, defeat_path, defeat_text_size);

    bool endGame = false;
    while(!endGame){
    
        SDL_Event event;    
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: endGame = true; break;
            }
        }
    }
}

void Session::victory(){
    clearRenderer();

    setTextMessage(victory_messsage, victory_path, victory_text_size);

    bool endGame = false;
    while(!endGame){
    
        SDL_Event event;    
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: endGame = true; break;
            }
        }
    }
}

void Session::endRun(bool victory){

    is_session_running_ = false;
    this->victory_ = victory;

}

void Session::setTextMessage(std::string message, std::string path, int size) {
    if (TTF_Init() == -1) {
        exit(-1);
    }
   
    font_ = TTF_OpenFont((constants::gResPath + path).c_str(), size);

    SDL_Color color = {77,255,64};
    
    SDL_Surface* textSurf = TTF_RenderText_Solid(font_, message.c_str(), color);

    SDL_Texture* txt = SDL_CreateTextureFromSurface(ses.getRenderer(), textSurf);
    SDL_Rect rect_ = {(syst_.getMaxX() - textSurf->w) / 2, (syst_.getMaxY() - textSurf->w) / 2, textSurf->w, textSurf->h};

    SDL_RenderCopy(ses.getRenderer(), txt, NULL, &rect_);
    SDL_RenderPresent(ses.getRenderer());
    SDL_FreeSurface(textSurf);
 
}

const std::vector<std::shared_ptr<Sprite>> Session::getSpriteVec() const{
    return sprites_;
}

std::shared_ptr<HUD> Session::getHUD() {
    return hud_;
}

void Session::handleEvent(SDL_Event& event){

       while(SDL_PollEvent(&event)){
            
            switch(event.type){
            
                case SDL_KEYUP: {
                    for(std::shared_ptr<Player> player : players_){
                        player->keyUp(event, syst_.getMaxX());
                    }  
                }break;

                case SDL_KEYDOWN: {
                    for(std::shared_ptr<Player> player : players_){ 
                        player->keyDown(event, syst_.getMaxX());
                    }   
                }break;

                case SDL_QUIT: is_session_running_ = false, userEndedSession = true; break;
        
            } // End of switch
        } // End of inner while loop
}

void Session::clearRenderer(){
    SDL_RenderClear(syst_.getRenderer());
}

void Session::handleTick(){
    for (SpritePtr sprite : sprites_) {
        sprite->tick();
    }
        
    for (auto player : players_) {
        player->tick();
    }
}

void Session::handleCreatedElements(){
    for (SpritePtr sprite : added_) {
        sprites_.push_back(std::move(sprite));
    }
    added_.clear();   
}

void Session::handleCollision(){

    if(sprites_.size() <= 1){
        return;
    }

    for(LongUInt i = 0; i < sprites_.size() - 1; i++){
        for(LongUInt j = (i + 1); j < sprites_.size(); j++){
            SpritePtr first = sprites_.at(i);
            SpritePtr second = sprites_.at(j);
                    
            bool collided = first->hasCollided(&first->getRect(), &second->getRect());
            if (collided) {
                first->getCollisionBehaviour();
                second->getCollisionBehaviour();
            }
                   
        } // End of inner for loop
    } // End of outer for loop

    for(LongUInt i = 0; i < sprites_.size(); i++){
        for(LongUInt j = 0; j < players_.size(); j++){
        
            SpritePtr first = sprites_.at(i);
            SpritePtr second = players_.at(j);

            bool collided = first->hasCollided(&first->getRect(), &second->getRect());
            if (collided) {
                first->getCollisionBehaviour();
                second->getCollisionBehaviour();
            }
        }
    }       
}

void Session::removeElements(){

     for (SpritePtr sprite : removed_) {
            for(SpriteVectorIterator i = sprites_.begin(); i != sprites_.end();){
                if(*i == sprite){
                    i = sprites_.erase(i);
                }
                else{
                    i++;
                }
            }
        }
        removed_.clear();
}

void Session::renderBackground(){
    SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);
}

void Session::invokeDrawOnElements(){

    for (SpritePtr sprite : sprites_) {
            sprite->draw();
    }

    for(PlayerPtr player : players_){
            player->draw();
    }

    hud_->draw();

}

void Session::displayElements(){
     SDL_RenderPresent(syst_.getRenderer());
}

int Session::determineDelay(Uint32 next_tick){
      return next_tick - SDL_GetTicks();
       
}

void Session::createDelay(int delay){
        if (delay > 0) {
            SDL_Delay(delay);
        }
}


Session ses(DEFAULT_HEIGHT, DEFAULT_WIDTH, DEFAULT_TITLE, DEFAULT_BACKGROUND);