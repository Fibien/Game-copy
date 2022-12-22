#include <memory>
#include <stdexcept>
#include <SDL2/SDL_image.h> 
#include "Session.h"
#include "Constants.h"
#include <iostream>

#define FPS 60

// Typedef have captital letter for every word
typedef std::shared_ptr<Sprite> SpritePtr;
typedef std::shared_ptr<Player> PlayerPtr;
typedef std::shared_ptr<HUD> HUDptr;
typedef std::vector<std::shared_ptr<Sprite>>::iterator SpriteVectorIterator;
typedef long long unsigned int LongUInt;


using namespace constants;

Session::Session(int x, int y, std::string title, std::string path_) : syst_(x, y, title, path_){}

Session::~Session() {
    TTF_CloseFont(font_);
    TTF_Quit();
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

        handleTick();

        handleCollision();

        removeElements();

        renderBackground();

        invokeDrawOnElements();
        
        displayElements();

        int delay = determineDelay(next_tick);
        createDelay(delay);
    } // End outer while

    if(!userEndedSession_){
        victory_ ? victory() : defeat();
    }
} // End run

void Session::addSprite(const std::shared_ptr<Sprite>& sprite) {
    added_.push_back(std::move(sprite));
}

void Session::addPlayer(std::shared_ptr<Player> player){
    if(is_session_running_){
        throw std::invalid_argument("Players can't be added during runtime");
    }
    player_ = player;
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

SDL_Texture* Session::getTexture(std::string key) {
    return syst_.getTexture(key);
}

SDL_Renderer* Session::getRenderer() {
    return syst_.getRenderer();
}

void Session::remove(const std::shared_ptr<Sprite> &sprite) {
    removed_.push_back(std::move(sprite));
}

void Session::setWindow(int height_, int width, std::string key) {
    syst_.setWindow(height_, width, key);
}

const std::vector<std::shared_ptr<Sprite>> Session::getSpriteVec() const{
    return sprites_;
}

std::shared_ptr<HUD> Session::getHUD() const {
    return hud_;
}

void Session::setDefeatMessage(std::string message, std::string path_, int size){
    defeat_messsage_ = message;
    defeat_path_ = path_;
    defeat_text_size_ = size;
}

void Session::setVictoryMessage(std::string message, std::string path_, int size){
    victory_messsage_ = message;
    victory_path_ = path_;
    victory_text_size_ = size;
}

void Session::winTheGame(){
    setEndGamePath(true);
}

void Session::looseTheGame(){
    setEndGamePath(false);
}

void Session::defeat(){
    displayPostScreen(defeat_messsage_, defeat_path_, defeat_text_size_);
}

void Session::victory(){
    displayPostScreen(victory_messsage_, victory_path_, victory_text_size_);
}

void Session::setEndGamePath(bool victory){
    is_session_running_ = false;
    this->victory_ = victory;
}

void Session::setTextMessage(std::string message, std::string path_, int size) {
    if (TTF_Init() == -1) {
        exit(-1);
    }
   
    font_ = TTF_OpenFont((constants::gResPath + path_).c_str(), size);
    SDL_Color color = {77,255,64};

    SDL_Surface* textSurf = TTF_RenderText_Solid(font_, message.c_str(), color);
    SDL_Texture* txt = SDL_CreateTextureFromSurface(ses.getRenderer(), textSurf);
    SDL_Rect rect_ = {(syst_.getMaxX() - textSurf->w) / 2, (syst_.getMaxY() - textSurf->w) / 2, textSurf->w, textSurf->h};

    SDL_RenderCopy(ses.getRenderer(), txt, NULL, &rect_);
    SDL_RenderPresent(ses.getRenderer());
    SDL_FreeSurface(textSurf);
}

void Session::displayPostScreen(std::string message, std::string path_, int text_size){

    clearRenderer();
    setTextMessage(message, path_, text_size);

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

void Session::handleEvent(SDL_Event& event){

    while(SDL_PollEvent(&event)){
            
        switch(event.type){
            
            case SDL_KEYUP: {
  
                if(event.key.keysym.sym == SDLK_SPACE){
                    if (shoot_timer_ > shoot_timer_limit) {
                        player_->shoot_();
                        shoot_timer_ = 0;
                    }
                }       

            }break;

            case SDL_KEYDOWN: {


                if(event.key.keysym.sym == SDLK_RIGHT){
                    player_->moveRight();
                }
                
                if(event.key.keysym.sym == SDLK_LEFT){
                    player_->moveLeft();
                }
            }break;

            case SDL_QUIT: is_session_running_ = false, userEndedSession_ = true; break;
        } // End of switch
    } // End of while loop
    shoot_timer_++;
}

void Session::clearRenderer(){
    SDL_RenderClear(syst_.getRenderer());
}

void Session::handleTick(){
    for (SpritePtr sprite : sprites_) {
        sprite->tick();
    }   
    player_->tick();
}

void Session::handleCreatedElements(){
    for (SpritePtr sprite : added_) {
        sprites_.push_back(std::move(sprite));
    }
    added_.clear();   
}

void Session::handleCollision(){
    // handleSpriteCollision();
    // handlePlayerCollision();
// If there exist only one sprite then no
    // collision can occur
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
        SpritePtr first = sprites_.at(i);
        bool collided = first->hasCollided(&first->getRect(), &player_->getRect());
        
        if (collided) {
            first->getCollisionBehaviour();
            player_->getCollisionBehaviour();
        }
    }  

}

void Session::handleSpriteCollision(){

    // If there exist only one sprite then no
    // collision can occur
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
}

void Session::handlePlayerCollision(){

      for(LongUInt i = 0; i < sprites_.size(); i++){
        SpritePtr first = sprites_.at(i);
        bool collided = first->hasCollided(&first->getRect(), &player_->getRect());
        
        if (collided) {
            first->getCollisionBehaviour();
            player_->getCollisionBehaviour();
        }
    }   
}

void Session::removeElements(){

    for (SpritePtr sprite : removed_) {
        for(SpriteVectorIterator i = sprites_.begin(); i != sprites_.end();){

            *i == sprite ? i = sprites_.erase(i) : i++;    
        
        } // inner for
    } // outher for
    removed_.clear();
}

void Session::renderBackground(){
    SDL_RenderCopy(syst_.getRenderer(), syst_.getBackgroundTexture(), NULL, NULL);
}

void Session::invokeDrawOnElements(){
    
    for (SpritePtr sprite : sprites_) {
        sprite->draw();
    }
    player_->draw();
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