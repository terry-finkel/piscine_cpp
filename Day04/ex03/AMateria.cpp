#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type), _xp(0) {}

AMateria::AMateria(AMateria const &rhs) { *this = rhs; }

AMateria &
AMateria::operator=(AMateria const &rhs) {

    _type = rhs._type;
    _xp = rhs._xp;
    return *this;
}

void
AMateria::addXP(unsigned int xp) {

    this->_xp += xp;
}

std::string const &
AMateria::getType() {

    return _type;
}

unsigned int
AMateria::getXP() const {

    return _xp;
}

void
AMateria::setXP(unsigned int xp) {

    _xp = xp;
}
