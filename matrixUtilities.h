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
 *
 * @param matrix
 * @return
 */
std::size_t minColumn(const Matrix& matrix);
/**
 *
 * @param matrix
 * @return
 */
VInt sumRow(const Matrix& matrix);
/**
 *
 * @param matrix
 * @return
 */
VInt sumColumn(const Matrix& matrix);
/**
 *
 * @param matrix
 * @return
 */
VInt vectSumMin(const Matrix& matrix);
/**
 *
 * @param matrix
 */
void shuffleMatrix(Matrix& matrix);
/**
 *
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
