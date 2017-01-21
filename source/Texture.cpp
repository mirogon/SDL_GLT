
#include "Texture.h"

C_Texture::C_Texture(){

    textureRect = new SDL_Rect;
    textureRect->x = 0;
    textureRect->y = 0;
    textureRect->w = 0;
    textureRect->h = 0;


    texture = nullptr;

}

C_Texture::~C_Texture(){

    SDL_DestroyTexture(this->texture);
    texture = nullptr;
    delete textureRect;
    textureRect = nullptr;

}

void C_Texture::FreeTexture(){

    if (texture != nullptr){

        SDL_DestroyTexture(texture);
        texture = nullptr;

    }
    
}

bool C_Texture::InitTexture(std::string path){

    FreeTexture();

    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface==nullptr){
    std::cout<<"Surface konnte nicht geladen werden: "<<std::endl<<SDL_GetError();
    }

    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255) );


    texture = SDL_CreateTextureFromSurface( _GetRenderer , surface );
    if(texture == nullptr){
    std::cout<<"Texture konnte nicht Erstellt werden: "<<std::endl<<SDL_GetError();
    }

    textureRect->w = surface->w;
    textureRect->h = surface->h;

    SDL_FreeSurface(surface);

    return texture != nullptr;
    
}

bool C_Texture::InitTextureFromText(std::string text, SDL_Color color){

    FreeTexture();

    SDL_Surface* loadText = TTF_RenderText_Solid(_GetFont, text.c_str(), color);
    if(loadText==nullptr){
    std::cout<<"TTF Surface konnte nicht erstellt werden"<<std::endl;
    }

    SDL_SetColorKey(loadText, SDL_TRUE, SDL_MapRGB(loadText->format, 255, 0, 255));

    texture = SDL_CreateTextureFromSurface(_GetRenderer, loadText);

    textureRect->w = loadText->w;
    textureRect->h = loadText->h;

    SDL_FreeSurface(loadText);

    return texture != nullptr;
    
}
