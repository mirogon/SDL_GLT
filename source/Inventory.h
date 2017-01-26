#pragma once
#include "Block.h"

#define _InventoryHUDPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/InventoryHUD.bmp"

struct InventoryList{
    
    short dirtBlocks;
    short stoneBlocks;
    
};

class C_Inventory{
    
public:
    
    C_Inventory();
    ~C_Inventory();
    
    void ReceiveBlock(BlockType rB);
    
    //INLINE METHODS
    
private:
    
    C_Texture* inventoryHUD;
    
};