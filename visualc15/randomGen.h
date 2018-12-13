#ifndef randomGen_h
#define randomGen_h
#include <cstdlib>
#include <time.h>

static int getRandom() {
	srand(time(NULL));
	int randNum = (rand() % 5) + 1;	// generates a number 1-5
	return randNum;
}

#endif
