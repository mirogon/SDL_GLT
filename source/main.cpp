#include "Game.h"

#define _BackgroundPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/Background.bmp"

int main(int argc, char** argv){

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){

        std::cout<<"SDL could not intialize!"<<std::endl;
        
    }

    else{

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

                else{

                    //Set the basic render color
                    SDL_SetRenderDrawColor(  C_Base::GetSingleton()->GetRenderer() , 0xFF, 0xFF, 0xFF, 0xFF );

                    //Clear the renderer with the basic render color
                    SDL_RenderClear(_GetRenderer);

                    backgroundTexture->RenderTexture(0,0);

                    mainGame.Game_Play();

                    //Sync the renderer with the window
                    SDL_RenderPresent(_GetRenderer);

                }
            }
        }
    }

    //Quit SDL
    C_Base::GetSingleton()->DeleteSingleton();
    SDL_Quit();

    return 0;
}
