#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {

    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &rhs) : Enemy(rhs) {

    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {

    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &
RadScorpion::operator=(RadScorpion const &rhs) {

    _HP = rhs._HP;
    _type = rhs._type;
    return *this;
}

void
RadScorpion::takeDamage(int damage) {

    if (_HP > 0) Enemy::takeDamage(damage);
}
