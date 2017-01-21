#include "Block.h"

C_Block::C_Block(BlockType b){

    xCoordinates = 0;
    yCoordinates = 0;

    blockType = b;

    blockTexture = new C_Texture;

    if(blockType==Dirt){

        blockTexture->InitTexture(_DirtBlockPath);
        if(blockTexture==nullptr){

            std::cout<<"BlockTexure could not be intialized!"<<std::endl;

        }

    }



}

C_Block::C_Block(){

    xCoordinates = 0;
    yCoordinates = 0;

    blockType = Dirt;

    blockTexture = new C_Texture;

}

C_Block::~C_Block(){

    delete blockTexture;

}

bool C_Block::InitBlock(long x, long y){

    xCoordinates = x;
    yCoordinates = y;


}

bool C_Block::InitBlock(long x, long y, BlockType b ){

    xCoordinates = x;
    yCoordinates = y;

    blockType = b;

    if(blockType==Dirt){

        blockTexture->InitTexture(_DirtBlockPath);
        
        if(blockTexture==nullptr){

            std::cout<<"BlockTexure could not be intialized!"<<std::endl;

        }

    }

}

bool C_Block::DespawnBlock(){

    this->~C_Block();


}


bool C_Block::RenderBlock(){

    blockTexture->RenderTexture(xCoordinates, yCoordinates);

}
