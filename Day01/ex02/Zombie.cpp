#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie::Zombie (std::string name, std::string type) : _name(name), _type(type) {}

Zombie::~Zombie () {

    std::cout << this->_name << " is melting away!" << std::endl;
}

void
Zombie::announce () const {

    std::ostringstream oss;
    oss << "<" << this->_name << " (" << this->_type << ")> FROMAGIIIIIIIIIIITE...";
    std::cout << oss.str() << std::endl;
}
