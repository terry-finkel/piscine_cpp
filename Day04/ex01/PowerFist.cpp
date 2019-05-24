#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &rhs) : AWeapon(rhs) {}

PowerFist &
PowerFist::operator=(PowerFist const &) {

    return *this;
}

void
PowerFist::attack() const {

    std::cout << "* pschhh... SBAM! *" << std::endl;
}
