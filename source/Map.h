#pragma once
#include "Block.h"

const int MapSizeX = 100;
const int MapSizeY = 50;

const int BlockOffsetY = 600;

#define _MapPath "/home/m1smr/Documents/C++/CodeLite/SDL_GLT/data/map.m1map"

class C_Map{

public:

C_Map();
~C_Map();

bool CreateMap();
bool RenderMap();
bool SaveMap();
bool LoadMap();

private:

std::vector<C_Block*> blockMap;


};
