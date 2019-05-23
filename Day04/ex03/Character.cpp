#include "Character.hpp"

Character::Character(std::string name) : _name(name) {

    for (int k = 0; k < MAX; k++) {
        _materias[k] = NULL;
    }
}

Character::Character(Character const &rhs) { *this = rhs; }

Character::~Character() {

    _deleteMaterias();
}

Character &
Character::operator=(Character const &rhs) {

    _name = rhs._name;
    _deleteMaterias();
    for (int k = 0; k < MAX; k++) {
        _materias[k] = rhs._materias[k];
    }

    return *this;
}

void
Character::_deleteMaterias() {

    for (int k = 0; k < MAX; k++) {
        if (_materias[k] != NULL) delete _materias[k];
    }
}

void
Character::equip(AMateria *materia) {

    for (int k = 0; materia != NULL && k < MAX; k++) {
        if (_materias[k] == NULL) _materias[k] = materia;
    }
}

std::string const &
Character::getName() const {

    return _name;
}

void
Character::unequip(int idx) {

    _materias[idx] = NULL;
}

void
Character::use(int idx, ICharacter &target) {

    if (idx < 4 && _materias[idx] != NULL) _materias[idx]->use(target);
}
