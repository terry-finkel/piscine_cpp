#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &rhs) : AWeapon(rhs) {}

PowerFist::~PowerFist() {}

PowerFist &
PowerFist::operator=(PowerFist const &rhs) {

    _APCost = rhs._APCost;
    _damage = rhs._damage;
    _name = rhs._name;
    return *this;
}

void
PowerFist::attack() const {

    std::cout << "* pschhh... SBAM! *" << std::endl;
}
