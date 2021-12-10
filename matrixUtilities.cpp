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
#include "utilities.h"       // required for random
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
 * the vector2. When one of the two vectors is empty, we sort it first
 * @param vector1
 * @param vector2
 * @return boolean true if the first value of the vector1 is smaller
 */
bool isFirstElemSmallerThan(const VInt& vector1, const VInt& vector2) {
	return (vector1.empty() || vector2.empty()) || vector1.front() < vector2.front();
}

// ----- utilities functions -----
bool isSquare(const Matrix& matrix){
	// Returns true if the matrix is empty, otherwise checks if the matrix is
	// regular AND if the size of a vector (since they are regular they have all
	// the same size, so we can take any vector) is equal to the size of the matrix
	return matrix.empty() ||
		    (isRegular(matrix) && matrix.front().size() == matrix.size());
}

bool isRegular(const Matrix& matrix){
	// Returns true if the matrix is empty, otherwise checks if every element has
	// the same size as the next one. If this is true, then it means that every
	// vector has the same size
	return matrix.empty() || equal(matrix.begin(), matrix.end() - 1,
											 matrix.begin() + 1, isSameSizeAs);
}

// ! This function is named "minCol" in the exercice, but we renamed it "minRow".
// We did it because it did not reflect what the function actually does
size_t minRow(const Matrix& matrix){
	// Return 0 if matrix is empty, otherwise compare the size of every row and
	// returns the size of the smallest
	return matrix.empty() ? 0 :
	       (*min_element(matrix.begin(), matrix.end(), isSmallerThan)).size();
}

VInt sumRow(const Matrix& m){
	if (m.empty()) return {};

	VInt result = VInt(m.size());
	// For each vector in the matrix, we sum the elements of the vector and put it
	// in a vector that is indexed in the same way as matrix (that is why we use a
	// "for int i" and not a "for auto i :", because we want the int index).
	for (size_t i = 0; i < m.size(); ++i) {
		result[i] = accumulate(m[i].begin(), m[i].end(), 0);
	}

   return result;
}

VInt sumColumn(const Matrix& matrix){
   VInt result;
   if(!matrix.empty()) {
      // Resizes result vector to the same size as the biggest vector in the matrix
		result.resize(
			(*max_element(matrix.begin(), matrix.end(), isSmallerThan)).size());

      // For each vector in the matrix increment the result vector (default value
      // is 0) adding the value of matrix[i][j] to result[j]
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

	// First, get a vector containing the sum of each row (indexed identically as
	// the matrix).
   VInt vSumRow = sumRow(m);
	// Then, we get index of the row with the smallest sum by getting the distance
	// between the being iterator and the min_element iterator.
	size_t indexOfMinSumRow = (size_t)distance(vSumRow.begin(),
	                          min_element(vSumRow.begin(), vSumRow.end()));
   // Since vSumRow is indexed identically as the matrix, we can access the matrix
	// with the same index
	return m[indexOfMinSumRow];
}

void shuffleMatrix(Matrix& matrix){
   if(!matrix.empty()) {
      // Shuffles the matrix elements using the random generator mt19937 seeded using
      // the ctime library
      shuffle(matrix.begin(), matrix.end(), mt19937(getRSeed()));
   }
}

void sortMatrix(Matrix& matrix){
	if (matrix.empty()) return;

	// Sort matrix by looking at the smallest first element of each row.
	sort(matrix.begin(), matrix.end(), isFirstElemSmallerThan);
}

ostream& operator<< (ostream& os,const VInt& vector){
   os << "(";
   // Loop to send in the ostream, the value at *i
   for(VInt::const_iterator i = vector.begin(); i != vector.end(); ++i){
      if(i != vector.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << ")";
   return os;
}

ostream& operator<< (ostream& os,const Matrix& matrix){
   os << "[";
   // Loop to send in the ostream, the vector at *i
   for(Matrix::const_iterator i = matrix.begin(); i != matrix.end(); ++i){
      if(i != matrix.begin()){
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}