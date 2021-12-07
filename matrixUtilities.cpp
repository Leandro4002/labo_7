/*
-----------------------------------------------------------------------------------
File name     : matrixUtilities.cpp
Authors       : Miguel Jalube, Leandro Saraiva Maia
Creation date : 07.12.2021

Description   : See matrixUtilities.h
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include "matrixUtilities.h"
#include <vector>          // required for
#include <algorithm>       // required for
#include <iostream>        // required for
#include <limits>          // required for

using namespace std;

// ----- predicates -----

// ----- utilities functions -----
bool isSquare(const Matrix& m){
   // TODO all
   return true;
}

bool isRegular(const Matrix& m){
	// TODO all
   return true;
}

size_t minColumn(const Matrix& m){
   // TODO all
   return 0ull;
}

int sumRow(const Matrix& m){
   // TODO all
   return 0;
}

int sumColumn(const Matrix& m){
   // TODO all
   return true;
}

VInt vectSumMin(const Matrix& m){
   // TODO all
   return {};
}

void shuffleMatrix(Matrix& m){
   // TODO all
}

void sortMatrix(Matrix& m){
   // TODO all
}

ostream& operator<< (ostream& os,const VInt& v){

}

ostream& operator<< (ostream& os,const Matrix& m){

}