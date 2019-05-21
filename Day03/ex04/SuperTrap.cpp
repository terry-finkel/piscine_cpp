#include "SuperTrap.hpp"
#include <sstream>

SuperTrap::SuperTrap () {

    std::cout << "*Unnamed SUP4R-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

SuperTrap::SuperTrap (std::string &name) : FragTrap (name), NinjaTrap (name) {

    std::ostringstream oss;
    oss << this;
    std::cout << "Hello! I am your new steward bot. Designation: SUP4R-TP, Hyperion Robot, Class S, unique identifier "
        << oss.str().substr(10) << ". You can call me " << name << "!" << std::endl;
}

SuperTrap::SuperTrap (SuperTrap const &rhs) : FragTrap (rhs), NinjaTrap (rhs) {

    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
//    std::cout << "Hello! I am your new steward bot. Designation: SUP4R-TP, Hyperion Robot, Class S, unique identifier "
//        << oss.str().substr(10) << ". You can call me " << this->_name << "!" << std::endl;
}

SuperTrap::~SuperTrap () {

    std::cout << this->_getIdentity() << " critical error. Shutdown now. ";
}

SuperTrap &
SuperTrap::operator = (SuperTrap const &rhs) {

    std::ostringstream oss;
    oss << &rhs;
    std::cout << this->_getIdentity() << ": restoring settings from copy " << oss.str().substr(10) << "." << std::endl;
    return *this;
}

std::string
SuperTrap::_getIdentity() const {

    std::string ret("<FR4G-TP> ");
    std::ostringstream oss;
    oss << this;
//    ret = ret + this->_name + "(" + oss.str().substr(10) + ")";
    return ret;
}
