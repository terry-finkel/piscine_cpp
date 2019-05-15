#include <iostream>

int
main () {

    std::string hello = "HI THIS IS BRAIN";
    std::string *pointer = &hello;
    std::string &ref = hello;

    std::cout << *pointer << std::endl;
    std::cout << ref << std::endl;

    return 0;
}