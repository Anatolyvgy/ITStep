#include<stdlib.h>
#include<time.h>
//#include"Random.h"
maxRandNumber = 10;

int myRand()
{
	srand(time(0));
	return rand( ) % (maxRandNumber + 1);
}