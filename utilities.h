/*
-----------------------------------------------------------------------------------
File name     : utilities.h
Authors       : Miguel Jalube, Leandro Saraiva Maia
Creation date : 07.12.2021

Description   : Provides miscellaneous utilities (currently, only about random)
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_07_VECTEURS_MATRICES_UTILITIES_H
#define INC_07_VECTEURS_MATRICES_UTILITIES_H

/**
 * Generate a random integer. This method also takes care of the seed
 * pseudo-randomization (based on time)
 * @return the generated int
 */
int getRandomIntBetween(int min, int max);

#endif //INC_07_VECTEURS_MATRICES_UTILITIES_H
