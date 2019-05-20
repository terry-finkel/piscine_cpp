#include "Fixed.class.hpp"
#include <iostream>

int
main () {

    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "A is " << a << std::endl;
    std::cout << "A is " << ++a << std::endl;
    std::cout << "A is " << a << std::endl;
    std::cout << "A is " << a++ << std::endl;
    std::cout << "A is " << a << std::endl;
    std::cout << "B is " << b << std::endl;
    std::cout << "max(A, B) is " << Fixed::max(a, b) << std::endl;
    std::cout << "min(A, B) is " << Fixed::min(a, b) << std::endl;
    std::cout << (a == b ? "A equal B" : "A doesn't equal B") << std::endl;

    Fixed c = b;

    std::cout << "B is " << b << std::endl;
    std::cout << "C is " << c << std::endl;
    std::cout << "max(B, C) is " << Fixed::max(b, c) << std::endl;
    std::cout << "min(B, C) is " << Fixed::min(b, c) << std::endl;
    std::cout << (b == c ? "B equal C" : "B doesn't equal C") << std::endl;

    Fixed d(a + b);
    std::cout << "D is " << d << std::endl;

    return 0;
}
