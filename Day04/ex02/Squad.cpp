#include "Squad.hpp"
#include <cstdlib>

Squad::Squad() : _count(0), _units(NULL) {}

Squad::Squad(Squad const &rhs) { *this = rhs; }

Squad::~Squad() {

//    for (int k = 0; k < this->getCount(); k++) delete this->getUnit(k);
}

Squad &
Squad::operator=(Squad const &rhs) {

    for (int k = 0; k < getCount(); k++) delete this->getUnit(k);
    for (int k = 0; k < rhs.getCount(); k++) _units[k] = rhs.getUnit(k);

    _count = rhs._count;
    return *this;
}

int
Squad::getCount() const {

    return _count;
}

Squad::unit_t *
Squad::_getLastLink () const {

    return _units;
}

ISpaceMarine *
Squad::getUnit(int N) const {

    if (N >= _count) return NULL;

    unit_t *unit = _units;
    for (int k = 0; k < N; k++) unit = unit->next;

    return unit->unit;
}

int
Squad::push(ISpaceMarine *spaceMarine) {

    if (spaceMarine == NULL) return -1;

    for (int k = 0; k < _count; k++) {
        if (spaceMarine == getUnit(k)) return -1;
    }

    _units[_count] = spaceMarine;
    _count += 1;
    return _count;
}
