//
//  bitvector.hpp
//  BooleanMatrix
//
//  Created by PWINZELL on 11/9/22.
//

#ifndef bitvector_hpp
#define bitvector_hpp

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<uint64_t> bits;

class bitVector{
private:
    bits bitar;
public:
    explicit bitVector  (int size);
    uint64_t SelectType();

    //index is calculated index = i*m + j , a(i,j)
    //indexbits is the slot where the bits are stored
    void setBits(int index,int indexbits, bool val){
        int bits = sizeof(uint64_t) * 8;
        int bitsize = index % bits;
        uint64_t bitnumber = uint64_t(bitsize);

        if (val == true) {
            bitar[indexbits] = bitar[indexbits] | (1 << bitnumber);
        } else {
            uint64_t  mask =  ~(1 << bitnumber);
            bitar[indexbits] &= mask;
        }
    };
    
    uint64_t getBitar(int index){
        return bitar[index];
    }

    bool isBitSet(int index,int bitnumber){
        uint64_t bits = bitar[index];
        return (bits & (1 << bitnumber));
    }
    
    void printBits(){
        for(int i=0; i < bitar.size(); i++){
            uint64_t bytes = bitar[i];
            for (int j=0; j < sizeof(uint64_t) * 8; j++){
                bool val = (bytes & (1 << j));
                cout << val;
            }
            cout << endl;
        }
    }


};


#endif /* bitvector_hpp */
