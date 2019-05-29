#include <iostream>

template <typename S, typename T>
void
iter(T address[], S size, void (*f)(T &)) {

    for (S k = 0; k < size; k++) {
        f(address[k]);
    }
}

void
print (int &a) {

    std::cout << a << std::endl;
}

int
main () {

    int a[] = { 5, 4, 3, 2, 1 };
    ::iter(a, 5, print);

    return 0;
}
