#pragma once
#include <time.h>
#include <stdlib.h>

class C_Random{
public:

C_Random();
int randomNumber(int min, int max);
virtual ~C_Random();

private:

time_t t;

};
