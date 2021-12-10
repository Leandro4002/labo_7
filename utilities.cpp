/*
-----------------------------------------------------------------------------------
File name     : utilities.cpp
Authors       : Miguel Jalube, Leandro Saraiva Maia
Creation date : 07.12.2021

Description   : See utilities.h
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include "utilities.h"
#include <random>
#include <cassert>
#include <ctime>

// TODO Check if used
int getRandomIntBetween(int min, int max) {
	assert(min < max);

	static bool seeded = false;
	if(!seeded) {
		srand((unsigned)time(nullptr));
		seeded = true;
	}

	return (std::rand() % (max - min) + min);
}

long long int getRSeed(){
   // Sets the random seed in static so is not resetted for each call
   static long long int seed = time(nullptr);
   return seed;
}