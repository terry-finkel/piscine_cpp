#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &rhs) : AMateria(rhs) {}

Cure::~Cure() {}

Cure &
Cure::operator=(Cure const &rhs) {

    this->setXP(rhs.getXP());
    return *this;
}

AMateria *
Cure::clone() const {

    AMateria *clone = new Cure(*this);
    return clone;
}

void
Cure::use(ICharacter &target) {

    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    addXP(10);
}
