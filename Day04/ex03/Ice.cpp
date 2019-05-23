#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &rhs) : AMateria(rhs) {}

Ice::~Ice() {}

Ice &
Ice::operator=(Ice const &rhs) {

    this->setXP(rhs.getXP());
}

AMateria *
Ice::clone() const {

    AMateria *clone = new Ice;
    return clone;
}

void
Ice::use(ICharacter &target) const {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
