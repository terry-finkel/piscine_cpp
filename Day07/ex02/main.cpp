#include "Array.tpp"
#include <iostream>

int
main () {

    Array<int> a(10);

    std::cout << "a size: " << a.size() << std::endl;

    for (size_t i = 0; i < a.size(); ++i) {
        a[i] = a.size() - i;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    Array<int> b;
    std::cout << "b size: " << b.size() << std::endl;

    b = a;
    std::cout << "b size: " << b.size() << std::endl;

    return 0;
}
