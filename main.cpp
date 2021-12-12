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

void test(Matrix& matrix);

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
		 {-5}},

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

void test(Matrix& matrix){
   cout << "Display vector       : ";
   if(matrix.empty()) {
      cout << "()";
   }else{
      cout << matrix.at(0);
   }
   cout << endl;
   cout << "Display matrix       : " << matrix << endl;
   cout << "Is square            : " << isSquare(matrix) << endl;
   cout << "Is regular           : " << isRegular(matrix) << endl;
   cout << "Minimum row size     : " << minRow(matrix) << endl;
   cout << "Row sum              : " << sumRow(matrix) << endl;
   cout << "Column sum           : " << sumColumn(matrix) << endl;
   cout << "Vector minimal sum   : " << vectSumMin(matrix) << endl;
   shuffleMatrix(matrix);
   cout << "Matrix after shuffle : " << matrix << endl;
   sortMatrix(matrix);
   cout << "Matrix after sort    : " << matrix << endl;
   cout << "----------------------------------------------------"<<endl;
}