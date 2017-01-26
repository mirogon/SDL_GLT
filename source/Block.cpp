#include "Block.h"

C_Block::C_Block(BlockType b){
    
    blockRectDouble = new double_Rect;
    
    blockRectDouble->x = 0;
    blockRectDouble->y = 0;
    
    blockRectDouble->w = BlockSize;
    blockRectDouble->h = BlockSize;
    
    blockType = b;

    if(dirtblockTexture == nullptr){
        
        dirtblockTexture = new C_Texture;
        dirtblockTexture->InitTexture(_DirtBlockPath);
        if(dirtblockTexture==nullptr){

            std::cout<<"dirtblockTexure could not be intialized!"<<std::endl;

        }
    }





}

C_Block::C_Block(){

    blockRectDouble = new double_Rect;
    
    blockRectDouble->x = 0;
    blockRectDouble->y = 0;
    
    blockRectDouble->w = BlockSize;
    blockRectDouble->h = BlockSize;
    
    blockType = Dirt;

    if(dirtblockTexture == nullptr){
        
        dirtblockTexture = new C_Texture;
        dirtblockTexture->InitTexture(_DirtBlockPath);
        if(dirtblockTexture==nullptr){

            std::cout<<"dirtblockTexure could not be intialized!"<<std::endl;

        }
    }

}

C_Block::~C_Block(){

    delete blockRectDouble;
    blockRectDouble = nullptr;
    
}

void C_Block::InitBlock(long x, long y){

    blockRectDouble->x = x;
    blockRectDouble->y = y;

}

void C_Block::InitBlock(long x, long y, BlockType b ){

    blockRectDouble->x = x;
    blockRectDouble->y = y;

    blockType = b;

}

void C_Block::ChangeBlockType(BlockType newBlockType){
    
    blockType = newBlockType;
    
}

void C_Block::DeleteStaticBlocks(){
    
    delete dirtblockTexture;
    dirtblockTexture = nullptr;
    
}

C_Texture* C_Block::dirtblockTexture = nullptr;


