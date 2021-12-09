/*
-----------------------------------------------------------------------------------
File name     : matrixUtilities.h
Authors       : Miguel Jalube, Leandro Saraiva Maia
Creation date : 07.12.2021

Description   : This library provides usefull functions to manipulate vectors and
                matrices
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_07_VECTEURS_MATRICES_MATRIXUTILITIES_H
#define INC_07_VECTEURS_MATRICES_MATRIXUTILITIES_H

#include <vector>
#include <iostream>           // required for operator<<

using VInt = std::vector<int>;
using Matrix = std::vector<VInt>;

/**
 * Checks if the matrix have the same number of lines and columns
 * @param   matrix the matrix to check
 * @return  boolean true if the matrix is square
 */
bool isSquare(const Matrix& matrix);

/**
 * Check if all the lines in a matrix have the same number of columns
 * @param   matrix the matrix to check
 * @return  boolean true if regular
 */
bool isRegular(const Matrix& matrix);

/**
 * Get the size of the smallest column
 * @param   matrix
 * @return  the size of the smallest column
 */
std::size_t minColumn(const Matrix& matrix);

/**
 * Returns a vector with the sum of each row of the matrix. The values are indexed
 * in the same order as the matrix. Example
 * m = { v1, v2, v3 }
 * sumRow(m) // returns { sumV1, sumV2, sumV3 }
 * @param matrix
 * @return
 */
VInt sumRow(const Matrix& matrix);

/**
 * Get the sum of the columns of the matrix and returns a vector with it
 * @param   matrix
 * @return  returns a vector with the addition of each column of the matrix
 */
VInt sumColumn(const Matrix& matrix);

/**
 * Get the row of the matrix with the lowest sum of elements. Example:
 * m = { {0, 0}, {5, -3}, {2, 1} }
 * vectSumMin(m) // returns {2, 1}
 * @param matrix
 * @return The row of the matrix that has the lowest sum
 */
VInt vectSumMin(const Matrix& matrix);

/**
 * Reorder the elements of the matrix randomly
 * @param matrix
 */
void shuffleMatrix(Matrix& matrix);

/**
 * Order matrix in ascending order of the first element of each row. Example :
 * m = { {4, 4}, {1, 3}, {2} }
 * sortMatrix(m) // m = { {1, 3}, {2}, {4, 4} }
 * @param matrix
 */
void sortMatrix(Matrix& matrix);

/**
 * Operator << for int vectors
 * @param os
 * @param vector
 * @return
 */
std::ostream& operator<< (std::ostream& os,const VInt& vector);

/**
 * Operator << for matrix (matrix = vector<vector<int>>)
 * @param   os
 * @param   matrix
 * @return  returns the ostream
 */
std::ostream& operator<< (std::ostream& os,const Matrix& matrix);

#endif //INC_07_VECTEURS_MATRICES_MATRIXUTILITIES_H
