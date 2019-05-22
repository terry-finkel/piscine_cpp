#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {

    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &rhs) : Enemy(rhs) {

    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {

    std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &
SuperMutant::operator=(SuperMutant const &rhs) {

    _HP = rhs._HP;
    _type = rhs._type;
    return *this;
}

void
SuperMutant::takeDamage(int damage) {

    if (_HP > 0) Enemy::takeDamage(damage - 3);
}
