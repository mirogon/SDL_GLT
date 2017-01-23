#include "Block.h"

C_Block::C_Block(BlockType b){
    
    blockRectDouble = new double_Rect;
    
    blockRectDouble->x = 0;
    blockRectDouble->y = 0;
    
    blockRectDouble->w = 50;
    blockRectDouble->h = 50;
    
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
    
    blockRectDouble->w = 50;
    blockRectDouble->h = 50;
    
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

}

bool C_Block::InitBlock(long x, long y){

    blockRectDouble->x = x;
    blockRectDouble->y = y;

}

bool C_Block::InitBlock(long x, long y, BlockType b ){

    blockRectDouble->x = x;
    blockRectDouble->y = y;

    blockType = b;

}

void C_Block::ChangeBlockType(BlockType newBlockType){
    
    blockType = newBlockType;
    
}

void C_Block::DeleteStaticBlocks(){
    
    delete dirtblockTexture;
    
}

C_Texture* C_Block::dirtblockTexture = nullptr;


