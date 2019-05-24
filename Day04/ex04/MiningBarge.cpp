#include "MiningBarge.hpp"
#include <iostream>

MiningBarge::MiningBarge() {

    for (int k = 0; k < LASERS; k++) {
        _lasers[k] = NULL;
    }
}

MiningBarge::MiningBarge(MiningBarge const &rhs) { *this = rhs; }

MiningBarge &
MiningBarge::operator=(MiningBarge const &rhs) {

    for (int k = 0; k < LASERS; k++) {
        _lasers[k] = rhs.getLasers()[k];
    }

    return *this;
}

void
MiningBarge::equip(IMiningLaser *laser) {

    int freeSlot = -1;
    for (int k = 0; k < LASERS; k++) {
        if (freeSlot == -1 && _lasers[k] == NULL) freeSlot = k;
        if (_lasers[k] == laser) {
            std::cout << "Trying to equip an already equipped laser..." << std::endl;
            return;
        }
    }

    _lasers[freeSlot] = laser;
    std::cout << "A new laser has been equipped!" << std::endl;
}

IMiningLaser *const *
MiningBarge::getLasers() const {

    return _lasers;
}

void
MiningBarge::mine(IAsteroid *asteroid) const {

    bool fail = true;
    for (int k = 0; k < LASERS; k++) {
        if (_lasers[k] != NULL) {
            _lasers[k]->mine(asteroid);
            fail = false;
        }
    }

    if (fail) std::cout << "The barge doesn't have lasers..." << std::endl;
}
