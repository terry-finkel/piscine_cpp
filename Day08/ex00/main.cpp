#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int		main( void ) {

    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(0);
    lst.push_back(20);

    std::cout << "List is: {10, 5, 15, 0, 20}" << std::endl << std::endl;

    std::cout << "Try to find 10 in list:" << std::endl;
    std::cout << "... returned index: " << easyfind(lst, 10) << std::endl  << std::endl;

    std::cout << "Try to find 20 in list:" << std::endl;
    std::cout << "... returned index: " << easyfind(lst, 20) << std::endl  << std::endl;

    try {
        std::cout << "Try to find 42 in list:" << std::endl;
        easyfind(lst, 520);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
