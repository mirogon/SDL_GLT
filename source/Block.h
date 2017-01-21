#pragma once
#include "Texture.h"

#define _DirtBlockPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/Dirt.bmp"

enum BlockType{Dirt = 0, Stone = 1};

class C_Block{

public:

C_Block(BlockType b);
C_Block();
~C_Block();

bool InitBlock(long x, long y);
bool InitBlock(long x, long y, BlockType b);
bool RenderBlock();
bool DespawnBlock();

//INLINE METHODS

long GetX();
long GetY();

BlockType GetBlockType();

private:

BlockType blockType;

C_Texture* blockTexture;

long xCoordinates;
long yCoordinates;


};

inline long C_Block::GetX(){

    return xCoordinates;

}

inline long C_Block::GetY(){

    return yCoordinates;

}

inline BlockType C_Block::GetBlockType(){

    return blockType;

}
