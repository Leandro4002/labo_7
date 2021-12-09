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
 *
 * @param matrix
 * @return
 */
bool isSquare(const Matrix& matrix);
/**
 *
 * @param matrix
 * @return
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
 *
 * @param os
 * @param vector
 * @return
 */
std::ostream& operator<< (std::ostream& os,const VInt& vector);
/**
 *
 * @param os
 * @param matrix
 * @return
 */
std::ostream& operator<< (std::ostream& os,const Matrix& matrix);

#endif //INC_07_VECTEURS_MATRICES_MATRIXUTILITIES_H
