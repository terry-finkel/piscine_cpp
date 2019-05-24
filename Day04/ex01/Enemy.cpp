#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : _HP(hp), _type(type) {}

Enemy::Enemy(Enemy const &rhs) { *this = rhs; }

Enemy &
Enemy::operator=(Enemy const &rhs) {

    _HP = rhs._HP;
    _type = rhs._type;
    return *this;
}

int
Enemy::getHP() const {

    return _HP;
}

std::string
Enemy::getType() const {

    return _type;
}

void
Enemy::takeDamage(int damage) {

    if (damage > 0) _HP = std::max(_HP - damage, 0);
}
