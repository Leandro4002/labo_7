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

#include "matrixUtilities.h" // Prototypes and aliases (Matrix, VInt)
#include <vector>            // required for internal use of vector (Matrix, VInt)
#include <algorithm>         // required for sort functions
#include <iostream>          // required for cout
#include <ctime>             // required to generate a seed based on time
#include <random>            // required to generate random numbers

using namespace std;

// ----- predicates -----
bool isSameSizeAs(const VInt& val1, const VInt& val2) {
	return val1.size() == val2.size();
}

bool isSmallerThan(const VInt& v1, const VInt& v2){
   return v1.size() < v2.size();
}

// ----- utilities functions -----
bool isSquare(const Matrix& m){
   bool square = m.empty();
   if(!square){
      square = isRegular(m) &&
			(*min_element(m.begin(), m.end(), isSmallerThan))
                     .size() == m.size();
   }
   return square;
}

bool isRegular(const Matrix& m){
	return m.empty() || equal(m.begin(), m.end() - 1, m.begin() + 1, isSameSizeAs);
}

size_t minColumn(const Matrix& m){
   size_t size = 0;
   if(!m.empty()){
		size = (*min_element(m.begin(), m.end(), isSmallerThan)).size();
   }
   return size;
}

VInt sumRow(const Matrix& m){
   // TODO all
   return {};
}

VInt sumColumn(const Matrix& m){
   VInt result;
   if(!m.empty()) {
		result.resize((*max_element(m.begin(), m.end(), isSmallerThan)).size());
      for (const VInt &i: m) {
         for (size_t j = 0; j < i.size(); ++j) {
            result.at(j) += i.at(j);
         }
      }
   }
   return result;
}

VInt vectSumMin(const Matrix& m){
   // TODO all
   return {};
}

void shuffleMatrix(Matrix& m){
   static long long int seed = time(nullptr);
   shuffle(m.begin(), m.end(), mt19937(seed));
}

void sortMatrix(Matrix& m){
   // TODO all
}

ostream& operator<< (ostream& os,const VInt& v){
   os << "[";
   for(VInt::const_iterator i = v.begin(); i != v.end(); ++i){
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
   for(Matrix::const_iterator i = m.begin(); i != m.end(); ++i){
      if(i != m.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}