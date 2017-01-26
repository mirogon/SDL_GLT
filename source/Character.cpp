#include "Character.h"


C_Character::C_Character(CharacterClass cC){
    
    currentCharacterClass = cC;
    
    switch(currentCharacterClass){
        
        case Warrior: break;
        case Mage: break;
        case Witcher: this->InitTexture(_WitcherPath); maxAnimationFrame = 4; frameDelay = 75; break;
        case Healer: break;
        default: maxAnimationFrame = 0; frameDelay = 0;
    }
    
    if(texture == nullptr){
        
        std::cout<<"Character could not be intialized"<<std::endl;
        
    }

    currentAnimationFrame = 0;

    
}

C_Character::~C_Character(){
    
    
    
}