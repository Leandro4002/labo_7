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
bool isSameSizeAs(const VInt& val1, const VInt& val2) {
	return val1.size() == val2.size();
}

bool isSmallerThan(const VInt& v1, const VInt& v2){
   return v1.size() < v2.size();
}

bool isGreaterThan(const VInt& v1, const VInt& v2){
   return v1.size() > v2.size();
}

// ----- utilities functions -----
bool isSquare(const Matrix& m){
   return min_element(m.begin(), m.end(), isSmallerThan) == max_element(m.begin()
      , m.end(), isGreaterThan);
}

bool isRegular(const Matrix& m){
	return equal(m.begin(), m.end() - 1, m.begin() + 1, isSameSizeAs);
}

size_t minColumn(const Matrix& m){
   // TODO all
   return 0ull;
}

VInt sumRow(const Matrix& m){
   // TODO all
   return 0;
}

VInt sumColumn(const Matrix& m){
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
   os << "[";
   for(auto i = v.begin(); i != v.end(); ++i){
      if(i != v.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}

ostream& operator<< (ostream& os,const Matrix& m){
   os << "[";
   for(auto i = m.begin(); i != m.end(); ++i){
      if(i != m.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}