#include "Game.h"

#define _BackgroundPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/Background.bmp"

int main(int argc, char** argv){

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){

        std::cout<<"SDL could not be intialized!"<<std::endl;
        
    }

    
    C_Texture* backgroundTexture = new C_Texture;
    backgroundTexture->InitTexture(_BackgroundPath);

    if(backgroundTexture==nullptr){

        std::cout<<"Backgroundtexture could not be intialized"<<std::endl;

    }

    bool quitPollEvent = false;
    SDL_Event pollEvent;

    C_Base::GetSingleton();

    C_Game mainGame;

    //Repeat as long as quitPollEvent = false
    while(quitPollEvent == false){

        while( SDL_PollEvent(&pollEvent) != 0){
                
            //If the windows will be closed quitpollevent = true
            if(pollEvent.type == SDL_QUIT){

                quitPollEvent = true;

            }
                
            if(pollEvent.type == SDL_KEYDOWN){
                    
                if(pollEvent.key.keysym.sym == SDLK_ESCAPE){
                        
                    quitPollEvent = true;
                        
                }
            }
        }
            
        //Clear the renderer with the basic render color
        SDL_RenderClear(_GetRenderer);

        backgroundTexture->RenderTexture(0,0);

        mainGame.Game_Play();

        //Sync the renderer with the window
        SDL_RenderPresent(_GetRenderer);
                    
        //Count fps
        static int countedFrames = 0;
        static Uint32 lastTimeCounted = SDL_GetTicks();
                    
        if(SDL_GetTicks() - lastTimeCounted >= 1000){
                        
            std::cout<<"FPS: "<<countedFrames<<std::endl;
                        countedFrames = 0;
            lastTimeCounted = SDL_GetTicks();
                        
        }

        ++countedFrames;
    }

    //Clear the memory and quit SDL
    delete backgroundTexture;
    C_Block::DeleteStaticBlocks();
    C_Base::GetSingleton()->DeleteSingleton();
    SDL_Quit();

    return 0;
}
