#include "ClapTrap.hpp"
#include <sstream>

ClapTrap::ClapTrap () : _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _meleeDMG(30), _rangedDMG(20),
                        _armor(5) {

    std::cout << "*Unnamed CL4P-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

ClapTrap::ClapTrap (std::string &name) :    _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _name(name),
                                            _meleeDMG(30), _rangedDMG(20), _armor(5) {

    std::ostringstream oss;
    oss << this;
    std::cout << "Booting sequence complete. ";
}

ClapTrap::ClapTrap (ClapTrap const &rhs) :  _HP(rhs._HP), _maxHP(rhs._maxHP), _EP(rhs._maxHP), _maxEP(rhs._maxEP),
                                            _level(rhs._level), _name(rhs._name), _meleeDMG(rhs._meleeDMG),
                                            _rangedDMG(rhs._rangedDMG), _armor(rhs._armor) {

    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Booting sequence complete. Settings have been copied from model " << oss2.str().substr(10) << ". ";
}

ClapTrap::~ClapTrap () {

    std::cout << "Goodbye!" << std::endl;
}

ClapTrap &
ClapTrap::operator = (ClapTrap const &rhs) {

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

void
ClapTrap::beRepaired (unsigned int amount) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (this->_HP == this->_maxHP) {
        std::cout << this->_getIdentity() << " is already fully repaired." << std::endl;
    } else {
        this->_HP = std::min(this->_maxHP, this->_HP + amount);
        std::cout << this->_getIdentity() << " is being repaired for " << amount << " HP!" << std::endl;
    }
}

std::string
ClapTrap::_getIdentity() const {

    std::string ret("<CL4P-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str().substr(10) + ")";
    return ret;
}

void
ClapTrap::meleeAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at melee, causing " << this->_meleeDMG
            << " points of damage!" << std::endl;
    }
}

void
ClapTrap::rangedAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at range, causing " << this->_rangedDMG
            << " points of damage!" << std::endl;
    }
}

void
ClapTrap::takeDamage (unsigned int amount) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else if (amount > this->_armor) {
        amount -= this->_armor;
        if (this->_HP > amount) {
            this->_HP -= amount;
            std::cout << this->_getIdentity() << " has taken " << amount << " points of damage!" << std::endl;
        } else {
            this->_HP = 0;
            std::cout << this->_getIdentity() << " has taken " << amount << " points of damage!" << std::endl
                << this->_getIdentity() << " has died!" << std::endl;
        }
    } else {
        std::cout << this->_getIdentity() << " is taking damage, but the armor absorbs it fully!" << std::endl;
    }
}
