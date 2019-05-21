#include "ScavTrap.hpp"
#include <sstream>

ScavTrap::ScavTrap () : _HP(100), _maxHP(100), _EP(50), _maxEP(50), _level(1), _meleeDMG(20), _rangedDMG(15),
                        _armor(3) {

    std::cout << "*Unnamed SC4V-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

ScavTrap::ScavTrap (std::string &name) :    _HP(100), _maxHP(100), _EP(50), _maxEP(50), _level(1), _name(name),
                                            _meleeDMG(20), _rangedDMG(15), _armor(3) {

    std::ostringstream oss;
    oss << this;
    std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: SC4V-TP, Hyperion Robot"
        ", Class B, unique identifier " << oss.str().substr(10) << ". You can call me " << name << "!" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &rhs) :  _HP(rhs._HP), _maxHP(rhs._maxHP), _EP(rhs._maxHP), _maxEP(rhs._maxEP),
                                            _level(rhs._level), _name(rhs._name), _meleeDMG(rhs._meleeDMG),
                                            _rangedDMG(rhs._rangedDMG), _armor(rhs._armor) {

    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Booting sequence complete. Settings have been copied from model " << oss2.str().substr(10)
        << ". Hello! I am your new steward bot. Designation: SC4V-TP, Hyperion Robot, Class B, unique identifier "
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

void
ScavTrap::beRepaired (unsigned int amount) {

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
ScavTrap::_getIdentity() const {

    std::string ret("<SC4V-TP> ");
    std::ostringstream oss;
    oss << this;
    ret = ret + this->_name + "(" + oss.str().substr(10) + ")";
    return ret;
}

void
ScavTrap::meleeAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at melee, causing " << this->_meleeDMG
            << " points of damage!" << std::endl;
    }
}

void
ScavTrap::rangedAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at range, causing " << this->_rangedDMG
            << " points of damage!" << std::endl;
    }
}

void
ScavTrap::takeDamage (unsigned int amount) {

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
