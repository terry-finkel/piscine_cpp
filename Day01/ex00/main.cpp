#include "Pony.hpp"
#include <iostream>

Pony *
ponyOnTheHeap () {

    std::string str = "heap";
    return new Pony(str, 7, 3);
}

Pony
ponyOnTheStack () {

    std::string str = "stack";
    return Pony(str, 3, 7);
}

int
main () {

    const Pony *heapPony = ponyOnTheHeap();
    const Pony stackPony = ponyOnTheStack();

    std::cout << "-------------------------------" << std::endl;
    heapPony->run();
    stackPony.run();
    std::cout << "-------------------------------" << std::endl;

    delete(heapPony);
    return 0;
}
