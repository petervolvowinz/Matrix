#include <iostream>
#include "src/bitvector.hpp"

int main() {

    bitVector bV(100);
    std::cout << bV.SelectType() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    bV.printBits();
    return 0;
}
