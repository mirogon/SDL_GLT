#pragma once
#include "Singleton.h"

class C_Timer{

public:


//Methods
C_Timer();


void StartTimer();
void RestartTimer();
void PauseTimer();
void ResumeTimer();
//Inline

Uint32 GetTicks();

private:

Uint32 startTicks;
Uint32 timerTicks;

bool isPaused;
};


inline Uint32 C_Timer::GetTicks(){

    if (isPaused==true){

        return timerTicks;

    }

    else if (isPaused==false){

        timerTicks = SDL_GetTicks() - startTicks;
        return timerTicks;
        
    }

};
