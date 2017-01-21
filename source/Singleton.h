#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>
#include <fstream>


template <typename T>
class C_Singleton{

public:



static T* GetSingleton(){

    if(Singleton==nullptr){

    Singleton = new T();

    }

    return Singleton;
}

void DeleteSingleton(){
delete Singleton;

}



private:

static T* Singleton;

protected:

C_Singleton(){}

};


template <typename T> T* C_Singleton<T>::Singleton = nullptr;
