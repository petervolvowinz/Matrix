//
// Created by PWINZELL on 11/16/22.
//

#include "gtest/gtest.h"
#include "../src/bmatrix.hpp"

TEST(bmatrix,GetDimensions){
    Matrix A(10,10);
    auto [n,m] = A.GetDimensions();
    EXPECT_EQ(10, n);
    EXPECT_EQ(10,m);
}

TEST(bmatrix,CopyConstr){
    Matrix A(10,10);
    bitVector bits = A.GetBits();
    Matrix B(A,bits);

    auto [n,m] = B.GetDimensions();

    EXPECT_EQ(10, n);
    EXPECT_EQ(10,m);

    Matrix C = B;

    auto [cn,cm] = C.GetDimensions();

    EXPECT_EQ(10, cn);
    EXPECT_EQ(10,cm);
}

TEST(bmatrix,SetGetIndex){
    Matrix A(5,5);
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            A.SetIndex(i,j,true);
        }
    }

    // A.PrintMatrix();
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            EXPECT_EQ(true,A.GetIndex(i,j));
        }
    }

    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            A.SetIndex(i,j,false);
        }
    }

    // A.PrintMatrix();

    for (int i = 1; i < 5; i++){
        for (int j = 1; j < 5; j++){
            EXPECT_EQ(false,A.GetIndex(i,j));
        }
    }


}

TEST(bmatrix,Addition){

    Matrix A(4,4);
    A.SetIndex(1,3,true);
    A.SetIndex(2,4,true);
    A.SetIndex(3,3,true);
    A.SetIndex(3,4,true);

    Matrix B(4,4);
    A.SetIndex(1,2,true);
    A.SetIndex(2,1,true);
    A.SetIndex(3,3,true);
    A.SetIndex(4,2,true);

    Matrix D = A.Add(B);

    Matrix C(4,4);
    C.SetIndex(1,2,true);
    C.SetIndex(1,3,true);
    C.SetIndex(2,1,true);
    C.SetIndex(2,4,true);
    C.SetIndex(3,2,true);
    C.SetIndex(3,3,true);
    C.SetIndex(3,4,true);
    C.SetIndex(4,2,true);

    for (int i = 1; i <= 4 ; i++){
        for (int j = 1; j <= 4 ; j++){
            EXPECT_EQ(D.GetIndex(i,j),C.GetIndex(i,j));
        }
    }

}

TEST(bmatrix,Multiply){
    Matrix A(3,3);
    A.SetIndex(1,1,true);
    A.SetIndex(1,2,true);
    A.SetIndex(1,3,true);
    A.SetIndex(2,1,true);
    A.SetIndex(2,3,true);
    A.SetIndex(3,2,true);

    Matrix B(3,3);
    B.SetIndex(1,1,true);
    B.SetIndex(2,3,true);
    B.SetIndex(3,1,true);
    B.SetIndex(3,2,true);
    B.SetIndex(3,3,true);

    Matrix C(3,3);
    C.SetIndex(1,1,true);
    C.SetIndex(1,2,true);
    C.SetIndex(1,3,true);
    C.SetIndex(2,1,true);
    C.SetIndex(2,2,true);
    C.SetIndex(2,3,true);
    C.SetIndex(3,3,true);

    Matrix D = A.Multiply(B);

    for (int i = 1; i <= 3 ; i++){
        for (int j = 1; j <= 3 ; j++){
            EXPECT_EQ(D.GetIndex(i,j),C.GetIndex(i,j));
        }
    }
}

//Testing that number of matrix A cols not equal with matrix B rows should throw exception.
TEST(bmatrix,invalid_multiplication){
    Matrix A(10,10);
    Matrix B(9,10);

    try{
        Matrix C = A.Multiply(B);
        FAIL();
    }
    catch(std::invalid_argument const& err ){
       EXPECT_EQ(std::string("cols in A not equal rows in B"),err.what());
    }
    catch(...){
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(bmatrix,new_dimensions){
    Matrix A(1,3);
    Matrix B(3,1);

    Matrix C = A.Multiply(B);
    auto [n,m] = C.GetDimensions();
    
    EXPECT_EQ(n,1);
    EXPECT_EQ(m,1);


}