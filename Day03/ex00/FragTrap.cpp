#include "FragTrap.hpp"
#include <sstream>

FragTrap::FragTrap () : _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _meleeDMG(30), _rangedDMG(20),
                        _armor(5) {

    std::cout << "*Unnamed FR4G-TP rises* Directive one: Protect humanity! Directive two: Obey Jack at all costs. "
        "Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap (std::string &name) :    _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _name(name),
                                            _meleeDMG(30), _rangedDMG(20), _armor(5) {

    std::ostringstream oss;
    oss << this;
    std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: FR4G-TP, Hyperion Robot"
        ", Class C, unique identifier " << oss.str().substr(10) << ". You can call me " << name << "!" << std::endl;
}

FragTrap::FragTrap (FragTrap const &rhs) :  _HP(rhs._HP), _maxHP(rhs._maxHP), _EP(rhs._maxHP), _maxEP(rhs._maxEP),
                                            _level(rhs._level), _name(rhs._name), _meleeDMG(rhs._meleeDMG),
                                            _rangedDMG(rhs._rangedDMG), _armor(rhs._armor) {

    std::ostringstream oss, oss2;
    oss << this;
    oss2 << &rhs;
    std::cout << "Booting sequence complete. Settings have been copied from model " << oss2.str().substr(10)
        << ". Hello! I am your new steward bot. Designation: FR4G-TP, Hyperion Robot, Class C, unique identifier "
        << oss.str().substr(10) << ". You can call me " << this->_name << "!" << std::endl;
}

FragTrap::~FragTrap () {}

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

void
FragTrap::beRepaired (unsigned int amount) {

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
FragTrap::_getIdentity() const {

    std::string ret(this->_name);
    std::ostringstream oss;
    oss << this;
    ret = ret + "(" + oss.str().substr(10) + ")";
    return ret;
}

void
FragTrap::meleeAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at melee, causing " << this->_meleeDMG
            << " points of damage!" << std::endl;
    }
}

void
FragTrap::rangedAttack (std::string const &target) {

    if (this->_HP == 0) {
        std::cout << this->_getIdentity() << " is dead..." << std::endl;
    } else {
        std::cout << this->_getIdentity() << " attacks " << target << " at range, causing " << this->_meleeDMG
            << " points of damage!" << std::endl;
    }
}

void
FragTrap::takeDamage (unsigned int amount) {

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
        int n = rand() % 4;
        std::cout << this->_getIdentity() << " is executing VaultHunter.exe on " << target << "..." << std::endl;
        std::cout << this->_getIdentity() << ": \"" << exe[n].name << "!\" " << target << exe[n].message << std::endl;

        if (n == 2) this->beRepaired(rand() % 100 + 25);
    }
}
