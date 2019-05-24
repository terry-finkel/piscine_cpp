#include "Peon.hpp"
#include <iostream>

Peon::Peon(std::string const name) : Victim (name) {

    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &rhs) : Victim (rhs) {}

Peon::~Peon() {

    std::cout << "Bleuark..." << std::endl;
}

Peon &
Peon::operator=(Peon const &rhs) {

    Victim::operator=(rhs);
    return *this;
}

void
Peon::getPolymorphed() const {

    std::cout << getName() << " has been turned into a pink pony !" << std::endl;
}
