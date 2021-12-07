/*
-----------------------------------------------------------------------------------
File name     : main.cpp
Lab name      :
Author(s)     : Leandro Saraiva Maia, Miguel Jalube
Creation date : 07.12.2021

Description   :
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>            // required for EXIT_SUCCESS
#include <iostream>           // required for cout
#include <limits>             // required for numeric_limits<...>
#include <vector>             // required to use vector
#include "matrixUtilities.h"  // required for matrix manipulations

using namespace std ;

void test(Matrix& m);

int main(){
   Matrix m1{
      {0,0,0},
      {0},
      {0,0},
      {0,0,0}
   };
   Matrix m2{
      {0,0,0},
      {0,1,-1},
      {0,0,2},
      {0,0,0}
   };
   Matrix m3;
   test(m1);
   test(m2);
   test(m3);

   cout << "Pressez ENTER pour terminer";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}

void test(Matrix& m){
   cout << "Afficher un vecteur : " << m.at(0) << endl;
   cout << "Afficher une matrice : " << m << endl;
   cout << "Est carre : " << boolalpha << isSquare(m) << endl;
   cout << "Est reguliere : " << boolalpha << isRegular(m) << endl;
   cout << "Longueur de la colonne min : " << boolalpha << isRegular(m) << endl;
   cout << "Somme de la ligne 1 : " << boolalpha << isRegular(m) << endl;

}