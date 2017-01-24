#include "Character.h"

const float moveSpeed = 0.25;

class C_Game{

public:

C_Game();

~C_Game();

//INLINE METHODS
void Game_Play(bool mouseDown);
void MoveMap() const;
void CheckMining() const;

private:

C_Map* gameMap;
C_Character* gameCharacter;

};

inline void C_Game::Game_Play(bool mouseDown){

    static bool firstloop = true;

    if(firstloop==true){

        gameMap->CreateMap();
        //gameMap->LoadMap();
        gameMap->MoveMap( ( MapSizeX / 2 ) * -BlockSize, 0);
        firstloop=false;

    }
            
    if(mouseDown){
        
        CheckMining();
        
    }

    MoveMap();
    
    gameMap->RenderMap();
    
    gameCharacter->RenderTexture(SCREEN_WIDTH / 2 - gameCharacter->GetRect()->w / 2,BlockOffsetY - gameCharacter->GetRect()->h);


}

inline void C_Game::MoveMap() const{
    
    static const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    
    static Uint32 lastTimeMoved = SDL_GetTicks();

    if(currentKeyStates[SDL_SCANCODE_D]){
         
        gameMap->MoveMap(( SDL_GetTicks() - lastTimeMoved ) * -moveSpeed ,0);
            
    }
        
    if(currentKeyStates[SDL_SCANCODE_A]){
        
        gameMap->MoveMap(( SDL_GetTicks() - lastTimeMoved ) * moveSpeed ,0);
            
    }

        
    lastTimeMoved = SDL_GetTicks();
    
    
}

inline void C_Game::CheckMining() const{
    
    int mouseX = 0, mouseY = 0;
    
    SDL_GetMouseState(&mouseX, &mouseY);
    
    gameMap->BlockToVoid(mouseX, mouseY);
    
}
