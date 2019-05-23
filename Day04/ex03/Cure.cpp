#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &rhs) : AMateria(rhs) {}

Cure::~Cure() {}

Cure &
Cure::operator=(Cure const &rhs) {

    this->setXP(rhs.getXP());
}

AMateria *
Cure::clone() const {

    AMateria *clone = new Cure;
    return clone;
}

void
Cure::use(ICharacter &target) const {

    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
