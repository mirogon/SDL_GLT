#include "Base.h"

C_Base::C_Base():

mainWindow
{

    SDL_CreateWindow("SDL_GLT by M1SMR/MIROGON", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN )

},

mainRenderer
{

    SDL_CreateRenderer(mainWindow, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

},

mainFont
{

    TTF_OpenFont( _FontPath, 28)

},

mainTimer
{
    
    new C_Timer}

{
    
    //Set the basic render color

    SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //std::cout<<"Window und Renderer wurden erstellt, Singleton wurde Erstellt"<<std::endl;

};

C_Base::~C_Base(){
    
    SDL_DestroyWindow(this->mainWindow);
    SDL_DestroyRenderer(this->mainRenderer);
    TTF_CloseFont(mainFont);
    delete mainTimer;
    mainTimer = nullptr;

};

