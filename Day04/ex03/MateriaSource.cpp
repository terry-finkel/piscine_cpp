#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

    for (int k = 0; k < MAX; k++) {
        _sources[k] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &rhs) { *this = rhs; }

MateriaSource::~MateriaSource() {

    _deleteSources();
}

MateriaSource &
MateriaSource::operator=(const MateriaSource &rhs) {

    _deleteSources();
    for (int k = 0; k < MAX; k++) {
        _sources[k] = rhs._sources[k];
    }

    return *this;
}

AMateria *
MateriaSource::createMateria(const std::string &type) {

    for (int k = 0; k < MAX; k++) {
        if (type == _sources[k]->getType()) return _sources[k]->clone();
    }

    return 0;
}

void
MateriaSource::_deleteSources() {

    for (int k = 0; k < MAX; k++) {
        if (_sources[k] != NULL) delete _sources[k];
    }
}

void
MateriaSource::learnMateria(AMateria *materia) {

    for (int k = 0; materia != NULL && k < MAX; k++) {
        if (_sources[k] == NULL) {
            _sources[k] = materia->clone();
            return;
        }
    }
}
