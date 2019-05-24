#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &rhs) : AWeapon(rhs) {}

PlasmaRifle &
PlasmaRifle::operator=(PlasmaRifle const &) {

    return *this;
}

void
PlasmaRifle::attack() const {

    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
