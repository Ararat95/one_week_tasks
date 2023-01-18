#include "BitVector.h"

int main() {
    Bitvector ob;
    // std::cout << ob.size() << std::endl;
    ob.set(28, 1);
    // ob.set(63, 1);
    // ob.set(127, 1);
    // ob.set(255, 1);
    // std::cout << ob.get(28) << std::endl;
    std::cout << ob[0] << std::endl;
    // std::cout << ob << std::endl;
    ob.set(60, 1);
    ob.set(92, 1);
    ob.set(29, 1);
    ob.set(61, 1);
    std::cout << ob << std::endl;
    ob.set(29, 0);
    ob.set(61, 0);
    std::cout << ob << std::endl;
    
    return 0;
}