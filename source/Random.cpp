
#include "Random.h"


int C_Random::randomNumber(int min, int max){

    time(&t);

    return (  rand()  % (max-min) ) + min  ;

}

C_Random::C_Random(){

    srand(static_cast<unsigned int>(t));

}

C_Random::~C_Random(){}


