#include "Map.h"

C_Map::C_Map(){

}


C_Map::~C_Map(){

    blockMap.clear();

}

bool C_Map::CreateMap(){

    for(int i=0; i<MapSizeX;i++){

        for(int o=0; o<MapSizeY;o++){

            static long num = 0;
            blockMap.push_back(new C_Block(Dirt));
            std::vector<C_Block*>::iterator mapIt = blockMap.begin();
            mapIt+= num;
            (*mapIt)->InitBlock(i*BlockSize, o*BlockSize + BlockOffsetY);
            std::cout<<"Block Nr. "<<num<<" xC: "<<(*mapIt)->GetX()<<" yC: "<<(*mapIt)->GetY()<<std::endl;

            num++;

        }

    }


    std::fstream saveMap( _MapPath , std::ios::out | std::ios::trunc);

    saveMap<<"x"<<MapSizeX;
    saveMap<<"y"<<MapSizeY;

    for(std::vector<C_Block*>::iterator i = blockMap.begin(); i<blockMap.end();i++){

        static long blockNum = 0;
        static int j = 1;

        saveMap<<"X"<<(*i)->GetX();
        saveMap<<"Y"<<(*i)->GetY();
        saveMap<<"t"<<(*i)->GetBlockType();
        saveMap<<";";

        if(j==10){

            saveMap<<std::endl;
            j=1;

        }

        ++blockNum;
        ++j;

    }

    saveMap.close();

}



bool C_Map::SaveMap(){

    std::fstream saveMap( _MapPath , std::ios::out | std::ios::trunc);

    saveMap<<"x"<<MapSizeX;
    saveMap<<"y"<<MapSizeY;

    for(std::vector<C_Block*>::iterator i = blockMap.begin(); i<blockMap.end();i++){

        static long blockNum = 0;
        static int j = 1;

        saveMap<<"X"<<(*i)->GetX();
        saveMap<<"Y"<<(*i)->GetY();
        saveMap<<"t"<<(*i)->GetBlockType();
        saveMap<<";";

        if(j==10){

            saveMap<<std::endl;
            j=1;

        }

        ++blockNum;
        ++j;

    }

    saveMap.close();

}

bool C_Map::LoadMap(){

    std::fstream loadMap (_MapPath, std::ios::in);

    char c;

    bool X = false, Y = false, x = false, y = false, t = false, semikolon = false;

    bool readblockType = false;
    bool readXCoordinate = false;
    bool readYCoordinate = false;
    bool readMapSizeX = false;
    bool readMapSizeY = false;

    bool enableInit = false;

    std::string mapSizeXString;
    std::string mapSizeYString;
    std::string loadedXCoordinateString;
    std::string loadedYCoordinateString;

    long savedMapSizeX = 0;
    long savedMapSizeY = 0;

    long savedBlockCoordinateX = 0;
    long savedBlockCoordinateY = 0;

    int savedBlockType;

    //WHILE fstream loadMap gets the character from the file
    while(loadMap.get(c)){

        switch(c){

            case 'x': x = true; break;
            case 'y': y = true; break;
            case 'X': X = true; break;
            case 'Y': Y = true; break;
            case 't': t = true; break;
            case ';': semikolon = true; break;

        }

        if(x == true){

            readMapSizeX = true;
            x = false;


        }

        if(y == true){

            readMapSizeY = true;
            y = false;


        }

        if(X == true){

            readXCoordinate = true;
            X = false;


        }

        if(Y == true){

            readYCoordinate = true;
            Y = false;


        }

        if(t == true){

            readblockType = true;
            t=false;


        }

        //IF THE CHARACTER IS A SEMIKOLON, THE NEXT BLOCK WILL BE READ
        if(semikolon==true){

            blockMap.push_back(new C_Block());
            enableInit=true;
            semikolon=false;

            mapSizeXString.clear();
            mapSizeYString.clear();
            loadedXCoordinateString.clear();
            loadedYCoordinateString.clear();


        }

        //READ MAPSIZE X FROM FILE
        if(readMapSizeX==true && ( c != 'y' ) && ( c != 'x') ){

            mapSizeXString.push_back(c);


        }

        else if ( readMapSizeX == true && ( c == 'y') ){

            savedMapSizeX = std::stol(mapSizeXString);
            readMapSizeX = false;

        }

        //READ MAPSIZE Y FROM FILE

        if(readMapSizeY==true && ( c != 'X') && ( c != 'y' )){

            mapSizeYString.push_back(c);


        }

        else if ( readMapSizeY == true && ( c == 'X' ) ){

            savedMapSizeY = std::stol(mapSizeYString);
            std::cout<<"Mapsize X: "<<savedMapSizeX<<" Mapsize Y: "<<savedMapSizeY<<std::endl;
            readMapSizeY = false;

        }

        //READ X COORDINATE FROM THIS BLOCK FROM THE FILE
        if(readXCoordinate==true &&( c != 'Y') && ( c != 'X' ) ){

            loadedXCoordinateString.push_back(c);

        }

        else if(readXCoordinate==true && ( c == 'Y')){

            savedBlockCoordinateX = stol(loadedXCoordinateString);
            readXCoordinate = false;

        }

        //READ X COORDINATE FROM THIS BLOCK FROM THE FILE

        if(readYCoordinate==true && ( c != 't') && ( c != 'Y' )){


            loadedYCoordinateString.push_back(c);

        }

        else if(readYCoordinate==true && ( c == 't') ){

            savedBlockCoordinateY = stol(loadedYCoordinateString);
            readYCoordinate = false;

        }

        if(readblockType==true && ( c != ';') && ( c != 't' )){

            savedBlockType = c - '0';
            readblockType = false;

        }

        //Sync the loaded with blockMap;
        BlockType castedBT;
        
        if(savedBlockType == 0){

            castedBT = Void;

        }
        
        else if(savedBlockType == 1){
            
            castedBT = Dirt;
            
        }
        
        else if(savedBlockType == 2){
            
            castedBT = Stone;
            
        }
        
        else{
            
            castedBT = Dirt;
            
        }
        
        if(enableInit==true){
            
            static long initLoop = 0;
            
            std::vector<C_Block*>::iterator iT = blockMap.begin();
            
            
            iT += initLoop;
            
            
            if((*iT)==nullptr){

                std::cout<<"NULLPTR iT"<<std::endl;
                std::cout<<"LOOP NUM: "<<initLoop<<std::endl;
                std::cout<<"BLOCKMAP SIZE: "<<blockMap.size()<<std::endl;

            }
            
            if(blockMap.size() >= 1){
                
                std::cout<<"LOOPNUM: "<<initLoop<<" BlockMap Size: "<<blockMap.size()<<" InitX: "<<savedBlockCoordinateX<<" InitY: "<<savedBlockCoordinateY<<std::endl;
                
                (*iT)->InitBlock(savedBlockCoordinateX, savedBlockCoordinateY, castedBT);
                
            }
            
            enableInit = false;
            ++initLoop;
            
        }

    }

}
