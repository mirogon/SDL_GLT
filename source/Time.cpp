
#include "Time.h"

C_Timer::C_Timer(){
   
    startTicks = 0;
    isPaused = false;

}

void C_Timer::StartTimer(){

    startTicks = SDL_GetTicks();

    timerTicks = (SDL_GetTicks() - startTicks);

}

void C_Timer::PauseTimer(){

    timerTicks = (SDL_GetTicks() - startTicks);

    isPaused = true;

}

void C_Timer::ResumeTimer(){

    isPaused = false;

}

void C_Timer::RestartTimer(){

    isPaused = false;
    startTicks = SDL_GetTicks();


}

