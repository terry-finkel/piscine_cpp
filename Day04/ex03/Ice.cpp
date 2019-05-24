#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &rhs) : AMateria(rhs) {}

Ice &
Ice::operator=(Ice const &rhs) {

    this->setXP(rhs.getXP());
    return *this;
}

AMateria *
Ice::clone() const {

    AMateria *clone = new Ice(*this);
    return clone;
}

void
Ice::use(ICharacter &target) {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    addXP(10);
}
