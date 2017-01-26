#pragma once
#include "Block.h"

const int MapSizeX = 1000;
const int MapSizeY = 100;

const int BlockOffsetY = 600;

#define _MapPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/map.m1map"

class C_Map{

public:

C_Map();
~C_Map();

void CreateMap();
void SaveMap();
void LoadMap();

//INLINE METHODS
void RenderMap();
void MoveMap(const double& xM, const double& yM);
void BlockToVoid(const int& x, const int& y);

private:

std::vector<C_Block*> blockMap;

};

inline void C_Map::RenderMap(){
    
    for(std::vector<C_Block*>::iterator i = blockMap.begin(); i != blockMap.end(); ++i){
        
        (*i)->RenderBlock();
        
    }

}

inline void C_Map::MoveMap(const double& xM, const double& yM){

         
    for(std::vector<C_Block*>::iterator i = blockMap.begin(); i !=  blockMap.end(); ++i){
            
        (*i)->MoveBlock(xM, yM);
            
    }

    
}

inline void C_Map::BlockToVoid(const int& x, const int& y){
    
    for(std::vector<C_Block*>::iterator i = blockMap.begin(); i !=  blockMap.end(); ++i){
            
       if( x > (*i)->GetX() && ( x < (*i)->GetX() + BlockSize ) ){
           
           if( y > (*i)->GetY() && ( y < (*i)->GetY() + BlockSize ) ){
               
               (*i)->ChangeBlockType(Void);
               
           }
           
       }  
            
    }
    
}