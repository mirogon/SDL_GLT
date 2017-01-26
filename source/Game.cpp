#include "Game.h"


C_Game::C_Game(){

    gameMap = new C_Map;
    gameCharacter = new C_Character(Witcher);

}

C_Game::~C_Game(){

    delete gameMap;
    gameMap = nullptr;
    delete gameCharacter;
    gameCharacter = nullptr;
}

void C_Game::Game_Save(){
    
    gameMap->SaveMap();
    
    
}
