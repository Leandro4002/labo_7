/*
-----------------------------------------------------------------------------------
File name     : main.cpp
Lab name      :
Author(s)     : Leandro Saraiva Maia
Creation date : 07.12.2021

Description   :
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>            // required for EXIT_SUCCESS
#include <iostream>           // required for cout
#include <limits>             // required for numeric_limits<...>
#include <vector>             // required to use vector
#include "matrixUtilities.h"  // required for matrix manipulations

using namespace std;

int main() {

   //----- End of program -----
   cout << "Press ENTER to quit.";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty buffer
   return EXIT_SUCCESS;
}