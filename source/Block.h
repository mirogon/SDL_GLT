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

C_Block();

C_Block(BlockType b);

~C_Block();

void InitBlock(long x, long y);
void InitBlock(long x, long y, BlockType b);

void ChangeBlockType(BlockType newBlockType);

static void DeleteStaticBlocks();

//INLINE METHODS
bool RenderBlock() const;
void MoveBlock(double& mX, double& mY);

long GetX() const;
long GetY() const;

BlockType GetBlockType() const;

private:

BlockType blockType;

static C_Texture* dirtblockTexture;

double_Rect* blockRectDouble;

};

inline bool C_Block::RenderBlock() const{
    
    switch(blockType){
        
        case Void: break;
        case Dirt:  dirtblockTexture->RenderTexture(blockRectDouble->x, blockRectDouble->y); break;
        case Stone: break;
        default: return 1; break;
    }
   
   return 0;

}

inline void C_Block::MoveBlock(double& mX, double& mY){
    
    blockRectDouble->x += mX;
    blockRectDouble->y += mY;
    
}


inline long C_Block::GetX() const{

    return blockRectDouble->x;

}

inline long C_Block::GetY() const{

    return blockRectDouble->y;

}

inline BlockType C_Block::GetBlockType() const{

    return blockType;

}


