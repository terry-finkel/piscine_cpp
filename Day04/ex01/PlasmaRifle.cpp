#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &rhs) : AWeapon(rhs) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle &
PlasmaRifle::operator=(PlasmaRifle const &rhs) {

    _APCost = rhs._APCost;
    _damage = rhs._damage;
    _name = rhs._name;
    return *this;
}

void
PlasmaRifle::attack() const {

    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
