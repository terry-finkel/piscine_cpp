#include "ScavTrap.hpp"
#include <sstream>

ScavTrap::ScavTrap () {

    std::cout << "*Unnamed SC4V-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

ScavTrap::ScavTrap (std::string &name) {

    this->_EP = 50;
    this->_maxEP = 50;
    this->_name = name;
    this->_meleeDMG = 20;
    this->_rangedDMG = 15;
    this->_armor = 3;
    std::ostringstream oss;
    oss << this;
    std::cout << "Hello! I am your new steward bot. Designation: SC4V-TP, Hyperion Robot, Class B, unique identifier "
        << oss.str().substr(10) << ". You can call me " << name << "!" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &rhs) {

    this->_EP = 50;
    this->_maxEP = 50;
    this->_name = rhs._name;
    this->_meleeDMG = 20;
    this->_rangedDMG = 15;
    this->_armor = 3;
    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Hello! I am your new steward bot. Designation: SC4V-TP, Hyperion Robot, Class B, unique identifier "
        << oss.str().substr(10) << ". You can call me " << this->_name << "!" << std::endl;
}

ScavTrap::~ScavTrap () {

    std::cout << this->_getIdentity() << " critical error. Shutdown now." << std::endl;
}

ScavTrap &
ScavTrap::operator = (ScavTrap const &rhs) {

    this->_HP = rhs._HP;
    this->_maxHP = rhs._maxHP;
    this->_EP = rhs._EP;
    this->_maxEP = rhs._maxEP;
    this->_level = rhs._level;
    this->_name = rhs._name;
    this->_meleeDMG = rhs._meleeDMG;
    this->_rangedDMG = rhs._rangedDMG;
    this->_armor = rhs._armor;

    std::ostringstream oss;
    oss << &rhs;
    std::cout << this->_getIdentity() << ": restoring settings from copy " << oss.str().substr(10) << "." << std::endl;
    return *this;
}

std::string
ScavTrap::_getIdentity() const {

    std::string ret("<SC4V-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str().substr(10) + ")";
    return ret;
}

void
ScavTrap::challengeNewcomer (std::string const &target) {

    const std::string challenges[5] = {
            "Do a hundred push-ups! Noooooow!!!!",
            "You need to find me a purring cat. It needs to be black and white.",
            "What's the square root of 21741.967919? You have 5 seconds.",
            "Bend forward and cough.",
            "I want drugs. Go find me some."
    };

    std::cout << this->_getIdentity() << " Good morrow " << target << ". Here is a challenge for you! "
        << challenges[rand() % 5] << std::endl;
}
