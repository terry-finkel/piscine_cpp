#include "Character.hpp"
#include <iostream>

Character::Character() {}

Character::Character(std::string const &name) : _AP(40), _name(name), _weapon(NULL) {}

Character::Character(Character const &rhs) { *this = rhs; }

Character::~Character() {}

Character &
Character::operator=(Character const &rhs) {

    this->_AP = rhs._AP;
    this->_name = rhs._name;
    this->_weapon = rhs._weapon;
    return *this;
}

void
Character::attack(Enemy *enemy) {

    if (_weapon != NULL) {
        if (_AP < _weapon->getAPCost()) {
            std::cout << _name << " is out of AP!" << std::endl;
            return;
        }
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _AP -= _weapon->getAPCost();
        _weapon->attack();
        enemy->takeDamage(_weapon->getDamage());

        if (enemy->getHP() <= 0) delete enemy;
    }
}

void
Character::equip(AWeapon *weapon) {

    _weapon = weapon;
}

int
Character::getAP() const {

    return _AP;
}

std::string
Character::getName() const {

    return _name;
}

AWeapon*
Character::getWeapon() const {

    return _weapon;
}

void
Character::recoverAP() {

    _AP = std::min(40, _AP + 10);
}

std::ostream &
operator<<(std::ostream &os, Character const &c) {

    std::cout << c.getName() << " has " << c.getAP() << " AP and ";
    if (c.getWeapon() == NULL) {
        std::cout << "is unarmed" << std::endl;
    } else {
        std::cout << "wields a " << c.getWeapon()->getName() << std::endl;
    }

    return os;
}
