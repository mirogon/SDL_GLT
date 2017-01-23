#pragma once
#include "Texture.h"

#define _DirtBlockPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/Dirt.bmp"

enum BlockType{Void = 0, Dirt = 1, Stone = 2};

struct double_Rect{

    double x;
    double y;
    int w;
    int h;

};

class C_Block{

public:

C_Block(BlockType b);
C_Block();
~C_Block();

bool InitBlock(long x, long y);
bool InitBlock(long x, long y, BlockType b);

void ChangeBlockType(BlockType newBlockType);

static void DeleteStaticBlocks();

//INLINE METHODS
bool RenderBlock();
bool MoveBlock(double mX, double mY);

long GetX();
long GetY();

BlockType GetBlockType();

private:

BlockType blockType;

static C_Texture* dirtblockTexture;

double_Rect* blockRectDouble;

};

inline long C_Block::GetX(){

    return blockRectDouble->x;

}

inline long C_Block::GetY(){

    return blockRectDouble->y;

}

inline BlockType C_Block::GetBlockType(){

    return blockType;

}

inline bool C_Block::MoveBlock(double mX, double mY){
    
    blockRectDouble->x += mX;
    blockRectDouble->y += mY;
    
}

inline bool C_Block::RenderBlock(){
    
    switch(blockType){
        
        case Void: break;
        case Dirt:  dirtblockTexture->RenderTexture(blockRectDouble->x, blockRectDouble->y); break;
        case Stone: break;
    }
   

}