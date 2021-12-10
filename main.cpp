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
#include <vector>             // required because of hidden use of vector
#include "matrixUtilities.h"  // required for matrix manipulations

using namespace std ;

void test(Matrix& m);

int main() {
	cout << boolalpha;

	Matrix testMatrices[] = {
		// ----- Square cases -----
		{{ 1, 4,-2},
		 { 2, 2, 2},
		 {-1,-1, 3}},

		{{ 3,-1, 2, 1},
		 { 4, 1, 0,-2},
		 { 0, 1, 3,-4},
		 {-3, 0, 2,-4}},

		{{1,5},
		 {3,1}},

		{{ 0, 0, 0},
		 { 0, 0, 0},
		 { 0, 0, 0}},

		// ----- Regular cases -----
		{{ 1, 2, 2},
       { 0, 1,-1},
       { 0, 0, 2},
       { 4, 5, 6}},

		{{ 1, 3, 2, 4},
       { 0, 1,-1, 4}},

		{{ 1, 2, 3, 4, 5}},

		{{ 0, 0, 0, 0},
       { 0, 0, 0, 0}},

		// ----- Irregular cases -----
 		{{ 1, 4},
		 { 0, 3, 0},
		 { 1, 5, 3}},

 		{{ 3, 0},
		 { 1,-1},
		 { 2}},

 		{{ 4, 0, -1, 1, -1, 0},
		 { 1,-1},
		 { 2, 1}},

		// ----- Empty cases -----
		{},

		{{}},

		{{},
		 {}},

		{{0,0,0},
		 {},
		 {0,0}},

		{},
		{{}},
		{{0}},
	};

	for (Matrix& testMatrix : testMatrices) {
		test(testMatrix);
	}

   //----- End of program -----
   cout << "Press ENTER to quit.";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty buffer
   return EXIT_SUCCESS;
}

void test(Matrix& m){
   cout << "Display vector       : ";
   if(m.empty()) {
      cout << "()";
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
   cout << "Matrix after shuffle : " << m << endl;
   sortMatrix(m);
   cout << "Matrix after sort    : " << m << endl;
   cout << "----------------------------------------------------"<<endl;
}