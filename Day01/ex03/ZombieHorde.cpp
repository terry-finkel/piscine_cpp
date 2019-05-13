#include "ZombieHorde.hpp"
#include <iostream>
#include <stdlib.h>

std::string names[] = {
        "Urr",
        "Prern",
        "Parr",
        "Lirnkaemm",
        "Raellgilf",
        "Dhorngut",
        "Bhisvaem",
        "Rheinlik",
        "Gligssignug",
        "Gillgaudgolf",
        "Fi",
        "Su",
        "Khieh",
        "Saemmil",
        "Fesval",
        "Gwurvean",
        "Tisvath",
        "Stervil",
        "Ucolgre",
        "Folgarkio"
};

ZombieHorde::ZombieHorde (int N) {

    std::string type = "Emmental";
    this->_amount = N;
    this->_horde = new Zombie[N];

    for (int k = 0; k < this->_amount; k++) {
        this->_horde[k].setName(names[rand() % names->length()]);
        this->_horde[k].setType(type);
    }

    this->announce();
}

ZombieHorde::~ZombieHorde () {

    delete [] this->_horde;
}

void
ZombieHorde::announce () const {

    for (int k = 0; k < this->_amount; k++) {
        this->_horde[k].announce();
    }
}
