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
Character::displayGear() const {

    std::cout << getName() << " has the following materias equipped:" << std::endl;
    for (int k = 0; k < MAX; k++) {
        AMateria *materia = getMaterias()[k];
        std::cout << " Slot [" << k << "]: ";
        if (materia) {
            std::cout << materia->getType() << ", XP = " << materia->getXP() << std::endl;
        } else {
            std::cout << "empty" << std::endl;
        }
    }
}

void
Character::equip(AMateria *materia) {

    for (int k = 0; materia != NULL && k < MAX; k++) {
        if (_materias[k] == NULL) {
            _materias[k] = materia;
            return;
        }
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

AMateria *const *
Character::getMaterias() const {

    return _materias;
}
