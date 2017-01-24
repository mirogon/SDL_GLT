#pragma once
#include "Time.h"



const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


#define _GetWindow ( ( C_Base::GetSingleton() )->GetWindow() )
#define _GetRenderer ( ( C_Base::GetSingleton() )->GetRenderer() )
#define _GetFont ( ( C_Base::GetSingleton() )->GetFont() )
#define _GetTimer ( ( C_Base::GetSingleton() )->GetTimer() )

#define _FontPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/opensans.ttf"

class C_Base : public C_Singleton<C_Base> {

friend class C_Singleton<C_Base>;

public:

//Methods

~C_Base();

//INLINE

SDL_Window* GetWindow() const;

SDL_Renderer* GetRenderer() const;

TTF_Font* GetFont() const;

C_Timer* GetTimer() const;


private:

SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
TTF_Font* mainFont;
C_Timer* mainTimer;

protected:

C_Base();



};

inline SDL_Window* C_Base::GetWindow() const{
        
    return mainWindow;

};

inline SDL_Renderer* C_Base::GetRenderer() const{
        
    return mainRenderer;

};

inline TTF_Font* C_Base::GetFont() const{
        
    return mainFont;

};

inline C_Timer* C_Base::GetTimer() const{
        
    return mainTimer;

};


