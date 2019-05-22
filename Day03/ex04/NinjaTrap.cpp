#include "NinjaTrap.hpp"
#include <sstream>

NinjaTrap::NinjaTrap (std::string &name) : ClapTrap (name) {

    this->_HP = 60;
    this->_maxHP = 60;
    this->_EP = 120;
    this->_maxEP = 120;
    this->_meleeDMG = 60;
    this->_rangedDMG = 5;
    this->_armor = 0;
    std::ostringstream oss;
    oss << this;
    std::cout << "Hello! I am your new steward bot. Designation: N1NJ4-TP, Hyperion Robot, Class N, unique identifier "
        << oss.str() << ". You can call me " << name << "!" << std::endl;
}

NinjaTrap::NinjaTrap (NinjaTrap const &rhs) : ClapTrap (rhs) {

    this->_HP = 60;
    this->_maxHP = 60;
    this->_EP = 120;
    this->_maxEP = 120;
    this->_meleeDMG = 60;
    this->_rangedDMG = 5;
    this->_armor = 0;
    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Hello! I am your new steward bot. Designation: N1NJ4-TP, Hyperion Robot, Class N, unique identifier "
        << oss.str() << ". You can call me " << this->_name << "!" << std::endl;
}

NinjaTrap::~NinjaTrap () {

    std::cout << this->_getIdentity() << " critical error. Shutdown now." << std::endl;
}

NinjaTrap &
NinjaTrap::operator = (NinjaTrap const &rhs) {

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

std::string
NinjaTrap::_getIdentity() const {

    std::string ret("<N1NJ4-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str() + ")";
    return ret;
}

void
NinjaTrap::ninjaShoebox (ClapTrap const &target) const {

    static_cast<void>(target);
    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_EP < 25) {
        std::cout << this->_getIdentity() << " is out of energy!" << std::endl;
    } else {
        std::cout << this->_getIdentity() << " is Shoeboxing a CL4P-TP! Nothing happens!" << std::endl;
    }
}

void
NinjaTrap::ninjaShoebox (FragTrap &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_EP < 25) {
        std::cout << this->_getIdentity() << " is out of energy!" << std::endl;
    } else {
        std::cout << this->_getIdentity() << " is Shoeboxing a FR4G-TP!" << std::endl;
        target.vaulthunter_dot_exe("everyone");
        target.vaulthunter_dot_exe("everyone");
        target.vaulthunter_dot_exe("everyone");
    }
}

void
NinjaTrap::ninjaShoebox (NinjaTrap &target) {

    static_cast<void>(target);
    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_EP < 25) {
        std::cout << this->_getIdentity() << " is out of energy!" << std::endl;
    } else {
        std::cout << this->_getIdentity() << " is Shoeboxing a N1NJ4-TP! The shoeboxed N1NJ4-TP is now shoeboxing "
            << this->_getIdentity() << "! It's a shoeboxinception!" << std::endl;
    }
}

void
NinjaTrap::ninjaShoebox (ScavTrap &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_EP < 25) {
        std::cout << this->_getIdentity() << " is out of energy!" << std::endl;
    } else {
        std::cout << this->_getIdentity() << " is Shoeboxing a SC4V-TP!" << std::endl;
        target.challengeNewcomer(this->_getIdentity());
    }
}
