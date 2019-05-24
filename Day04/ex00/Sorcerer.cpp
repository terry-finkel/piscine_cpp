#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string const name, std::string const title) : _name(name), _title(title) {

    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &rhs) {

    *this = rhs;
}

Sorcerer::~Sorcerer() {

    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &
Sorcerer::operator=(Sorcerer const &rhs) {

    _name = rhs._name;
    _title = rhs._title;
    return *this;
}

std::string
Sorcerer::getName() const {

    return _name;
}

std::string
Sorcerer::getTitle() const {

    return _title;
}

void
Sorcerer::polymorph(Victim const &victim) {

    victim.getPolymorphed();
}

std::ostream &
operator<<(std::ostream &os, Sorcerer const &sorcerer) {

    os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
    return os;
}
