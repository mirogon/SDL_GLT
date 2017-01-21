#include "Game.h"

void C_Game::Game_Play(){

    static bool firstloop = true;

    if(firstloop==true){

        //gameMap->CreateMap();
        gameMap->LoadMap();
        firstloop=false;

    }

    gameMap->RenderMap();
    gameCharacter->RenderTexture(SCREEN_WIDTH / 2 - gameCharacter->GetRect()->w / 2,BlockOffsetY - gameCharacter->GetRect()->h);


}

C_Game::C_Game(){

    gameMap = new C_Map;
    gameCharacter = new C_Character;

}

C_Game::~C_Game(){

    delete gameMap;

}
