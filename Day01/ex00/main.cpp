#include "Pony.hpp"
#include <iostream>

Pony *
ponyOnTheHeap (void) {

    return new Pony("heap", 7, 3);
}

Pony
ponyOnTheStack (void) {

    return Pony("stack", 3, 7);
}

int
main (void) {

    const Pony *heapPony = ponyOnTheHeap();
    const Pony stackPony = ponyOnTheStack();

    std::cout << "-------------------------------" << std::endl;
    heapPony->run();
    stackPony.run();
    std::cout << "-------------------------------" << std::endl;

    delete(heapPony);
    return 0;
}
