#include "Pony.hpp"
#include <iostream>

Pony::Pony (std::string &type, const int heads, const int legs) : _heads(heads), _legs(legs), _type(type) {

    std::cout << "I'm a " << this->_type << " pony! I have " << this->_heads << " heads and " << this->_legs
    << " legs!" << std::endl;
}

Pony::~Pony () {

    std::cout << "I'm a " << this->_type << " pony and I leave this cruel world!" << std::endl;
}

void
Pony::run () const {

    std::cout << "I'm a " << this->_type << " pony! I'm running in the wild!" << std::endl;
}
