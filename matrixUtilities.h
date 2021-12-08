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
 * @param m
 * @return
 */
bool isSquare(const Matrix& m);
/**
 *
 * @param m
 * @return
 */
bool isRegular(const Matrix& m);
/**
 *
 * @param m
 * @return
 */
std::size_t minColumn(const Matrix& m);
/**
 *
 * @param m
 * @return
 */
VInt sumRow(const Matrix& m);
/**
 *
 * @param m
 * @return
 */
VInt sumColumn(const Matrix& m);
/**
 *
 * @param m
 * @return
 */
VInt vectSumMin(const Matrix& m);
/**
 *
 * @param m
 */
void shuffleMatrix(Matrix& m);
/**
 *
 * @param m
 */
void sortMatrix(Matrix& m);
/**
 *
 * @param os
 * @param v
 * @return
 */
std::ostream& operator<< (std::ostream& os,const VInt& v);
/**
 *
 * @param os
 * @param m
 * @return
 */
std::ostream& operator<< (std::ostream& os,const Matrix& m);

#endif //INC_07_VECTEURS_MATRICES_MATRIXUTILITIES_H
