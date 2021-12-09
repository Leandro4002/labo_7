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
#include <numeric>           // required for accumulate
#include <iterator>          // required for distance()
#include <iostream>          // required for cout
#include <ctime>             // required to generate a seed based on time
#include <random>            // required to generate random numbers

using namespace std;

// ----- predicates -----
/**
 * Checks if 2 vectors have the same size
 * @param vector1
 * @param vector2
 * @return boolean true if vectors have the same size
 */
bool isSameSizeAs(const VInt& vector1, const VInt& vector2) {
	return vector1.size() == vector2.size();
}
/**
 * Checks if vector1 smaller than vector2
 * @param vector1
 * @param vector2
 * @return boolean true if vector1 is smaller
 */
bool isSmallerThan(const VInt& vector1, const VInt& vector2){
   return vector1.size() < vector2.size();
}

/**
 * Checks if the first element of the vector1 is smaller than the first element of
 * the vector2
 * @param vector1
 * @param vector2
 * @return boolean true if the first value of the vector1 is smaller
 */
bool isFirstElemSmallerThan(const VInt& vector1, const VInt& vector2) {
	return vector1.at(0) < vector2.at(0);
}

// ----- utilities functions -----
bool isSquare(const Matrix& matrix){
   bool square = matrix.empty();
   if(!square){
      square = isRegular(matrix) &&
               (*min_element(matrix.begin(), matrix.end(), isSmallerThan))
                     .size() == matrix.size();
   }
   return square;
}

bool isRegular(const Matrix& matrix){
	return matrix.empty() || equal(matrix.begin(), matrix.end() - 1, matrix.begin() + 1, isSameSizeAs);
}

size_t minColumn(const Matrix& matrix){
   size_t size = 0;
   if(!matrix.empty()){
		size = (*min_element(matrix.begin(), matrix.end(), isSmallerThan)).size();
   }
   return size;
}

VInt sumRow(const Matrix& m){
	if (m.empty()) return {};

	VInt result = VInt(m.size());
	for (size_t i = 0; i < m.size(); ++i) {
		result[i] = accumulate(m[i].begin(), m[i].end(), 0);
	}

   return result;
}

VInt sumColumn(const Matrix& matrix){
   VInt result;
   if(!matrix.empty()) {
		result.resize((*max_element(matrix.begin(), matrix.end(), isSmallerThan)).size());
      // TODO : with accumulate and transform
      for (const VInt &i: matrix) {
         for (size_t j = 0; j < i.size(); ++j) {
            result.at(j) += i.at(j);
         }
      }
   }
   return result;
}

VInt vectSumMin(const Matrix& m){
	if (m.empty()) return {};

   VInt vSumRow = sumRow(m);
	size_t indexOfMinSumRow = (size_t)distance(vSumRow.begin(),
	                          min_element(vSumRow.begin(), vSumRow.end()));

	return m[indexOfMinSumRow];
}

void shuffleMatrix(Matrix& matrix){
   static long long int seed = time(nullptr);
   shuffle(matrix.begin(), matrix.end(), mt19937(seed));
}

void sortMatrix(Matrix& matrix){
	if (matrix.empty()) return;

	sort(matrix.begin(), matrix.end(), isFirstElemSmallerThan);
}

ostream& operator<< (ostream& os,const VInt& vector){
   os << "[";
   for(VInt::const_iterator i = vector.begin(); i != vector.end(); ++i){
      if(i != vector.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}

ostream& operator<< (ostream& os,const Matrix& matrix){
   os << "[";
   for(Matrix::const_iterator i = matrix.begin(); i != matrix.end(); ++i){
      if(i != matrix.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}