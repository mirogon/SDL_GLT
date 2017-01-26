#pragma once
#include "Map.h"

#define _WarriorPath
#define _WarriorSpriteW
#define _WarriorW
#define _WarriorH
const short warriorAnimationFrames = 0;

#define _MagePath
#define _MageSpriteW
#define _MageW
#define _MageH
const short mageAnimationFrames = 0;

#define _WitcherPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/Witcher.bmp"
#define _WitcherSpriteW 625
#define _WitcherW 125
#define _WitcherH 125
const short witcherAnimationFrames = 5;

#define _HealerPath
#define _HealerSpriteW
#define _HealerW
#define _HealerH
const short healerAnimationFrames = 0;


enum CharacterClass{
    
    Warrior = 0,
    Mage = 1,
    Witcher = 2,
    Healer = 3
    
};

class C_Character : public C_Texture{

public:

C_Character(CharacterClass cC);
~C_Character();

//INLINE METHODS
void WalkAnimation();
void RenderCharacter();

private:

short currentAnimationFrame;
short maxAnimationFrame;
short frameDelay;


CharacterClass currentCharacterClass;

};


inline void C_Character::WalkAnimation(){
    
    static Uint32 lastFrame = SDL_GetTicks();
    
    
    if(SDL_GetTicks() - lastFrame >= frameDelay){
        
        ++currentAnimationFrame;
        
        lastFrame = SDL_GetTicks();
        
    }
    
    if(currentAnimationFrame > maxAnimationFrame){
        
        currentAnimationFrame = 0;
        
    }
    
    
}

inline void C_Character::RenderCharacter(){
    
    static SDL_Rect frameSrcClip;
    
    static SDL_Rect frameDstClip;
    
    
    if(currentCharacterClass == Warrior){
        
        
    }
    
    else if(currentCharacterClass == Mage){
        
        
        
    }
    
    else if(currentCharacterClass == Witcher){
        
        frameSrcClip.w = _WitcherW;
        frameSrcClip.h = _WitcherH;
        frameSrcClip.x = currentAnimationFrame * _WitcherW;
        frameSrcClip.y = 0;
        
        frameDstClip.w = _WitcherW;
        frameDstClip.h = _WitcherH;
        frameDstClip.x = SCREEN_WIDTH / 2 - (textureRect->w / _WitcherW) / 2;
        frameDstClip.y = BlockOffsetY - textureRect->h;
        
    }
    
    else if(currentCharacterClass == Healer){
        
        
        
    }

    RenderTexture(0, 0, &frameSrcClip, &frameDstClip);
    
}