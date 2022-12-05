//
// Created by PWINZELL on 11/16/22.
//

#include "gtest/gtest.h"
#include "../src/bitvector.hpp"

class TestbitVector {
private:
    int n = 10;
    int m = 10;
    bitVector bV;
public:
    TestbitVector():bV(n*m){
    }

    bitVector OddTest() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ii = i - 1;
                int jj = j - 1;
                if (jj % 2 == 0) {
                    int index = ii * m + jj;
                    bV.setBits(index, index / (sizeof(uint64_t) * 8), true);
                }
            }

        }
        return bV;
    }

    bitVector ClearBitVector(){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ii = i - 1;
                int jj = j - 1;
                // clear even bit numbers
                if (jj % 2 == 0){
                    int index = ii * m + jj;
                    bV.setBits(index, index / (sizeof(uint64_t) * 8), false);
                }
            }
        }
        return bV;

    }

    void PrintBits(){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ii = i - 1;
                int jj = j - 1;
                int index = ii * m + jj;

                int bitsize = (sizeof(uint64_t) * 8);
                int slot = index /  bitsize;

                cout << bV.isBitSet(slot,index % bitsize);

            }
            cout << endl;
        }
    }

    bool GetBit(int index) {
        int bitnumber = bitnumber % 64;
        return (bV.getBitar(index) & (1 << bitnumber));
    }
};


TEST(bitVector, SelectType) {
    TestbitVector testbitVector;
    bitVector bV = testbitVector.OddTest();
    // Test that bitVector 0 returns 0
    EXPECT_EQ(0, bV.SelectType());
}

TEST(bitVector, setBits) {
    TestbitVector testbitVector;
    bitVector bV = testbitVector.OddTest();
    // bV.printBits();
    // testbitVector.PrintBits();
    for (int index = 0; index < 2; index++){
        for (int i = 0; i < 64; i += 2) {
            EXPECT_EQ(true, bV.isBitSet(index, i));
        }
        for (int i = 1; i < 63; i += 2) {
            EXPECT_EQ(false, bV.isBitSet(index, i));
        }
    }
}

TEST(bitVector, clearBits){
    TestbitVector testbitVector;
    bitVector bV = testbitVector.OddTest();
    bV = testbitVector.ClearBitVector();
    //bV.printBits();
    // testbitVector.PrintBits();
    for (int index = 0; index < 2; index++){
        for (int i = 1; i <= 64; i++) {
            EXPECT_EQ(false, bV.isBitSet(index, i));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}