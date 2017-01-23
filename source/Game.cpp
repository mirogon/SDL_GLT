#include "Game.h"


C_Game::C_Game(){

    gameMap = new C_Map;
    gameCharacter = new C_Character;

}

C_Game::~C_Game(){

    delete gameMap;
    gameMap = nullptr;
    delete gameCharacter;
    gameCharacter = nullptr;
}

