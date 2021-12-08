/*
-----------------------------------------------------------------------------------
File name     : main.cpp
Lab name      : Lab 7, Vectors and matrices
Authors       : Miguel Jalube, Leandro Saraiva Maia
Creation date : 07.12.2021

Description   : This program tests the functions given by the matrixUtilites
 					 library.
Remark(s)     : An empty matrix is considered as square and regular. irregular
                matrices are ignored.

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>            // required for EXIT_SUCCESS
#include <iostream>           // required for cout
#include <limits>             // required for numeric_limits<...>
#include <vector>             // required to use vector
#include "matrixUtilities.h"  // required for matrix manipulations

using namespace std ;

void test(Matrix& m);

int main() {
	cout << boolalpha;

   Matrix m1{
      {0,0,0},
      {0},
      {0,0},
      {0,0,0}
   };
   Matrix m2{
      {1,2,3},
      {0,1,-1},
      {0,0,2},
      {4,5,6}
   };
   Matrix m3;
   Matrix m4{
      {0,0,0},
      {0,1,-1},
      {0,0,2}
   };
   test(m1);
   test(m2);
   test(m3);
   test(m4);

   //----- End of program -----
   cout << "Press ENTER to quit.";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty buffer
   return EXIT_SUCCESS;
}

void test(Matrix& m){
   cout << "Display vector       : ";
   if(m.empty()) {
      cout << "[]";
   }else{
      cout << m.at(0);
   }
   cout << endl;
   cout << "Display matrix       : " << m << endl;
   cout << "Is square            : " << isSquare(m) << endl;
   cout << "Is regular           : " << isRegular(m) << endl;
   cout << "Minimum column size  : " << minColumn(m) << endl;
   cout << "Row sum              : " << sumRow(m) << endl;
   cout << "Column sum           : " << sumColumn(m) << endl;
   cout << "Vector minimal sum   : " << vectSumMin(m) << endl;
   shuffleMatrix(m);
   cout << "Matrix shuffle       : " << m << endl;
   sortMatrix(m);
   cout << "Matrix sort          : " << m << endl;
   cout << "----------------------------------------------------"<<endl;
}