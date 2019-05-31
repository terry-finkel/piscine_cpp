#include "span.hpp"
#include <cstdlib>
#include <iostream>

int
main () {

    span stackSpan = span(5);

    try {
        stackSpan.longestSpan();
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    stackSpan.addNumber(-5);
    stackSpan.addNumber(-1000);
    stackSpan.addNumber(-17);
    stackSpan.addNumber(-9);
    stackSpan.addNumber(-7);

    std::cout << "Stack shortest span: " << stackSpan.shortestSpan() << std::endl;
    std::cout << "Stack longest span: " << stackSpan.longestSpan() << std::endl;

    srand(time(0));
    span *heapSpan = new span(10000);

    for (int k = 0; k < 10000; k++) {
        int num = rand();
        heapSpan->addNumber(num);
    }

    std::cout << "Heap shortest span: " << heapSpan->shortestSpan() << std::endl;
    std::cout << "Heap longest span: " << heapSpan->longestSpan() << std::endl;

    delete heapSpan;
    return 0;
}
