#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie::~Zombie () {

    std::cout << this->_name << " is melting away!" << std::endl;
}

std::string
Zombie::getName () const {

    return this->_name;
}

void
Zombie::setName (std::string &name) {

    this->_name = name;
}

void
Zombie::setType (std::string &type) {

    this->_type = type;
}

void
Zombie::announce () const {

    std::ostringstream oss;
    oss << "<" << this->_name << " (" << this->_type << ")> FROMAGIIIIIIIIIIITE...";
    std::cout << oss.str() << std::endl;
}
