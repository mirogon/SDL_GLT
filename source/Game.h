#include "Character.h"


class C_Game{


public:

C_Game();

~C_Game();

void Game_Play();

private:

C_Map* gameMap;
C_Character* gameCharacter;

};
