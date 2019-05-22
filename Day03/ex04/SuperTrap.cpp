#include "SuperTrap.hpp"
#include <sstream>

SuperTrap::SuperTrap (std::string &name) : ClapTrap (name), FragTrap (name), NinjaTrap (name) {

    this->_HP = 100;
    this->_maxHP = 100;
    this->_EP = 120;
    this->_maxEP = 120;
    this->_meleeDMG = 60;
    this->_rangedDMG = 20;
    this->_armor = 5;
    std::ostringstream oss;
    oss << this;
    std::cout << "Hello! I am your new steward bot. Designation: SUP4R-TP, Hyperion Robot, Class S, unique identifier "
        << oss.str() << ". You can call me " << this->_name << "!" << std::endl;
}

SuperTrap::SuperTrap (SuperTrap const &rhs) : ClapTrap (rhs), FragTrap (rhs), NinjaTrap (rhs) {

    this->_HP = 100;
    this->_maxHP = 100;
    this->_EP = 120;
    this->_maxEP = 120;
    this->_meleeDMG = 60;
    this->_rangedDMG = 20;
    this->_armor = 5;
    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Hello! I am your new steward bot. Designation: SUP4R-TP, Hyperion Robot, Class S, unique identifier "
        << oss.str() << ". You can call me " << this->_name << "!" << std::endl;
}

SuperTrap::~SuperTrap () {

    std::cout << this->_getIdentity() << " critical error. Shutdown now." << std::endl;
}

SuperTrap &
SuperTrap::operator = (SuperTrap const &rhs) {

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
    std::cout << this->_getIdentity() << ": restoring settings from copy " << oss.str() << "." << std::endl;
    return *this;
}

void
SuperTrap::meleeAttack (std::string const &target) const {

    NinjaTrap::meleeAttack(target);
}

void
SuperTrap::rangedAttack (std::string const &target) const {

    FragTrap::rangedAttack(target);
}

void
SuperTrap::ninjaShoebox (ClapTrap const &target) const {

    NinjaTrap::ninjaShoebox(target);
}

void
SuperTrap::ninjaShoebox (FragTrap &target) {

    NinjaTrap::ninjaShoebox(target);
}

void
SuperTrap::ninjaShoebox (NinjaTrap &target) {

    NinjaTrap::ninjaShoebox(target);
}

void
SuperTrap::ninjaShoebox (ScavTrap &target) {

    NinjaTrap::ninjaShoebox(target);
}

void
SuperTrap::vaulthunter_dot_exe (std::string const &target) {

    FragTrap::vaulthunter_dot_exe(target);
}

std::string
SuperTrap::_getIdentity() const {

    std::string ret("<SUP4R-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str() + ")";
    return ret;
}
