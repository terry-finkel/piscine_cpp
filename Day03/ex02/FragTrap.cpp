#include "FragTrap.hpp"
#include <sstream>

FragTrap::FragTrap () {

    std::cout << "*Unnamed FR4G-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap (std::string &name) {

    this->_name = name;
    std::ostringstream oss;
    oss << this;
    std::cout << "Hello! I am your new steward bot. Designation: FR4G-TP, Hyperion Robot, Class C, unique identifier "
        << oss.str().substr(10) << ". You can call me " << name << "!" << std::endl;
}

FragTrap::FragTrap (FragTrap const &rhs) {

    this->_name = rhs._name;
    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Hello! I am your new steward bot. Designation: FR4G-TP, Hyperion Robot, Class C, unique identifier "
        << oss.str().substr(10) << ". You can call me " << this->_name << "!" << std::endl;
}

FragTrap::~FragTrap () {

    std::cout << this->_getIdentity() << " critical error. Shutdown now." << std::endl;
}

FragTrap &
FragTrap::operator = (FragTrap const &rhs) {

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
FragTrap::_getIdentity() const {

    std::string ret("<FR4G-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str().substr(10) + ")";
    return ret;
}

void
FragTrap::vaulthunter_dot_exe (std::string const &target) {

    struct s_exe {
            std::string name;
            std::string message;
    } exe[5] = {
            {"Gun Wizard", " is being crippled by a bullet storm!"},
            {"Laser Inferno", " is being burnt by inferno lasers!"},
            {"Medbot", " is watching in disbelief as his enemy greatly heals itself!"},
            {"Funzerker", " is being assaulted by a thousand weapons!"},
            {"Senseless Sacrifice", " is being obliterated!"}
    };

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_EP < 25) {
        std::cout << this->_getIdentity() << " is out of energy!" << std::endl;
    } else {
        this->_EP -= 25;
        int n = rand() % 5;
        std::cout << this->_getIdentity() << " is executing VaultHunter.exe on " << target << "..." << std::endl;
        std::cout << this->_getIdentity() << ":\"" << exe[n].name << "!\" " << target << exe[n].message << std::endl;

        if (n == 2) this->beRepaired(rand() % 100 + 25);
    }
}
