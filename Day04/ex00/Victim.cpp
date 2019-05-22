#include "Victim.hpp"
#include <iostream>

Victim::Victim () {}

Victim::Victim (std::string const name) : _name(name) {

    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim (Victim const &rhs) {

    *this = rhs;
}

Victim::~Victim () {

    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

Victim &
Victim::operator = (Victim const &rhs) {

    _name = rhs._name;
    return *this;
}

std::string
Victim::getName () const {

    return _name;
}

void
Victim::getPolymorphed () const {

    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &
operator << (std::ostream &os, Victim const &victim) {

    os << "I'm " << victim.getName() << " and i like otters !" << std::endl;
    return os;
}
