#include "Character.hpp"

Character::Character(std::string &name) : _name(name) {}

Character::Character(Character const &rhs) { *this = rhs; }

Character::~Character() {}

Character &
Character::operator=(Character const &rhs) {

    return *this;
}

void
Character::equip(AMateria *) {


}

std::string const &
Character::getName() const {

    return _name;
}

void
Character::unequip(int) {


}

void
Character::use(int idx, ICharacter &target) {

    if (idx < 4 && _materias[idx] != NULL) _materias[idx]->use(target);
}
