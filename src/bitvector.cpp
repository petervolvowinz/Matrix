//
//  bitvector.cpp
//  BooleanMatrix
//
//  Created by PWINZELL on 11/9/22.
//

#include "bitvector.hpp"

bitVector::bitVector(int size){
    int t_size =  sizeof(uint64_t) * 8;
    int slots = (size / t_size) + std::min(size % t_size, 1);
    // bitar.reserve(slots);
    bitar.resize(slots);
}

uint64_t bitVector::SelectType(){
    return uint64_t(0);
}
