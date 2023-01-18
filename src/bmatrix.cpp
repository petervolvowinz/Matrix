//
//  bmatrix.cpp
//  BooleanMatrix
//
//  Created by PWINZELL on 11/8/22.
//

#include "bmatrix.hpp"
#include<tuple>

using namespace std;


Matrix:: ~Matrix()
{

}

Matrix::Matrix(int n, int m):bits(n*m),n(n),m(m){
}

Matrix::Matrix(const Matrix &a, bitVector bits) : bits(bits) {
    n = a.n;
    m = a.m;
}

 Matrix& Matrix::operator=(const Matrix &a){
    bits = a.bits;
    n = a.n;
    m = a.m;
}

void Matrix::SetIndex(int i, int j,bool val){
    i--;
    j--;
    
    if (( (i < 0) || i > (n - 1)) || (j < 0 || j > (m-1))) {
        throw std::out_of_range(" index out of range ");
    }
    
    int index = (i * this -> m) + j;
    int slot = index / (sizeof(uint64_t) * 8);
    
    bits.setBits(index,slot,val);
}

bool Matrix::GetIndex(int i,int j){
    i--;
    j--;
    
    if (( (i < 0) || i > (n - 1)) || (j < 0 || j > (m-1))) {
        throw std::out_of_range(" index out of range ");
    }
        
        
    int bytes = sizeof(uint64_t);

    int index = (i * this -> m) + j;
    int bitnumber = index % (bytes * 8);
    int bitindex = index / (bytes * 8);
    
    return int ( bits.getBitar(bitindex) & (1 << bitnumber)) > 0;
    
}

void Matrix::PrintMatrix(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (GetIndex(i,j)){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << std::endl;
    }
}


Matrix Matrix::Multiply(Matrix B){
    int a_cols = this -> m;
    int b_rows = B.n;

    if  (a_cols != b_rows) {
        throw std::invalid_argument("cols in A not equal rows in B");
    }

    Matrix C = Matrix(this -> n, B.m); // The product has the dim = (Rows_A,Cols_B)

    for (int i = 1; i <= this -> n; i++) {
        bool sum = false;
        for (int j = 1; j <= B.m; j++) {
            for (int k = 1; k <= B.n; k++) {
                sum = (sum || (this -> GetIndex(i, k) && B.GetIndex(k, j)));
            }
            C.SetIndex(i, j, sum);
        }
    }

    return C;
}


Matrix Matrix::Add(Matrix B){
    if ((this -> n != B.n) || (this -> m != B.m)){
        throw std::invalid_argument("A and B is not the same size , addition not valid");
    }
    
    Matrix C = Matrix(this -> n, this -> m);
    
    for (int i = 1; i <= this -> n; i++) {
        for (int j = 1; j <= this -> m; j++) {
            C.SetIndex(i, j, this -> GetIndex(i, j) || B.GetIndex(i, j));
        }
    }
    return C;
}
