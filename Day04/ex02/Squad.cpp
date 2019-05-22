#include "Squad.hpp"
#include <cstdlib>

Squad::Squad() : _count(0), _head(NULL), _tail(NULL) {}

Squad::Squad(Squad const &rhs) { *this = rhs; }

Squad::~Squad() {

    this->_deleteSquad();
}

Squad &
Squad::operator=(Squad const &rhs) {

    this->_deleteSquad();

    if (rhs.getCount() > 0) {
        _head = new Squad::unit_t;
        _head->unit = rhs.getUnit(0);
        _head->next = NULL;
        _tail = _head;
    }

    for (int k = 1; k < rhs.getCount(); k++) {
        _tail->next = new Squad::unit_t;
        _tail->unit = rhs.getUnit(k);
        _tail = _tail->next;
    }

    _count = rhs._count;
    return *this;
}

void
Squad::_deleteSquad() {

    for (int k = 0; k < this->getCount(); k++) {
        Squad::unit_t *tmp = _head;
        _head = _head->next;
        delete tmp->unit;
        delete tmp;
    }
}

int
Squad::getCount() const {

    return _count;
}

ISpaceMarine *
Squad::getUnit(int N) const {

    if (N >= _count) return NULL;

    Squad::unit_t *unit = _head;
    for (int k = 0; k < N; k++) {
        unit = unit->next;
    }

    return unit->unit;
}

int
Squad::push(ISpaceMarine *spaceMarine) {

    if (spaceMarine == NULL) return -1;

    for (int k = 0; k < _count; k++) {
        if (spaceMarine == getUnit(k)) return -1;
    }

    Squad::unit_t *ptr = (_head == NULL ? (_head = new Squad::unit_t) : (_tail->next = new Squad::unit_t));
    ptr->unit = spaceMarine;
    ptr->next = NULL;
    _tail = ptr;
    _count += 1;
    return _count;
}
