//
//  bmatrix.hpp
//  BooleanMatrix
//
//  Created by PWINZELL on 11/8/22.
//

#ifndef bmatrix_hpp
#define bmatrix_hpp

#include <stdio.h>
#include <tuple>
#include "bitvector.hpp"

using namespace std;


class Matrix {
private:
    bitVector bits;
    int n,m;
public:

    bitVector GetBits(){
        return bits;
    }
    void SetIndex(int i, int j,bool val);
    bool GetIndex(int i, int j);
    void PrintMatrix();
    Matrix Multiply(Matrix B);
    Matrix Add(Matrix B);
    
    tuple<int,int> GetDimensions(){
     return make_tuple(n,m);
    }
    tuple<int,int,int> GetSizeInBytesBits(){
        return make_tuple(0,0,0);
    }
    
    Matrix  (int n,int m);         // construct a Matrix with specified size
    Matrix(const Matrix &a, bitVector bits);       // copy constructor
    ~Matrix ();                     // destructor
    Matrix& operator = (const Matrix& a);   // assignment operator
};

#endif /* bmatrix_hpp */
