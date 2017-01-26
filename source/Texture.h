#pragma once
#include "Base.h"

class C_Texture{

public:

//METHODS

C_Texture();
virtual ~C_Texture();

bool InitTexture (std::string path);
bool InitTextureFromText(std::string text, SDL_Color = {0,0,0});
void FreeTexture();


//INLINE

void RenderTexture (int x, int y);
void RenderTexture (int x, int y, SDL_Rect* clip);
void RenderTexture (int x, int y, SDL_Rect* clip, SDL_Rect* clip2);
void RenderTextureRotated(int x, int y, SDL_Rect* clip, double degree = 0);
const SDL_Rect* GetRect() const;
SDL_Texture* GetTexture() const;

protected:

SDL_Rect* textureRect;
SDL_Texture* texture;

};



inline void C_Texture::RenderTexture(int x, int y){


    textureRect->x = x;
    textureRect->y = y;


    SDL_RenderCopy(_GetRenderer, texture, NULL, textureRect);


}


inline void C_Texture::RenderTexture(int x, int y, SDL_Rect* clip){

    textureRect->x = x;
    textureRect->y = y;


    SDL_RenderCopy(_GetRenderer, this->texture, clip, textureRect);

}

inline void C_Texture::RenderTexture(int x, int y, SDL_Rect* clip, SDL_Rect* clip2){

    textureRect->x = x;
    textureRect->y = y;


    SDL_RenderCopy(_GetRenderer, this->texture, clip, clip2);

}

inline void C_Texture::RenderTextureRotated(int x, int y, SDL_Rect* clip, double degree){


    textureRect->x = x;
    textureRect->y = y;


    SDL_RenderCopyEx(_GetRenderer, this->texture, clip, textureRect, degree, NULL, SDL_FLIP_NONE);


}

inline const SDL_Rect* C_Texture::GetRect() const{
        
    return textureRect;

}

inline SDL_Texture* C_Texture::GetTexture() const{

    return texture;

}