#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _APCost(apcost), _damage(damage), _name(name) {}

AWeapon::AWeapon(AWeapon const &rhs) { *this = rhs; }

AWeapon::~AWeapon() {}

AWeapon &
AWeapon::operator=(AWeapon const &rhs) {

    _APCost = rhs._APCost;
    _damage = rhs._damage;
    _name = rhs._name;
    return *this;
}

int
AWeapon::getAPCost() const {

    return _APCost;
}

int
AWeapon::getDamage() const {

    return _damage;
}

std::string
AWeapon::getName() const {

    return _name;
}
