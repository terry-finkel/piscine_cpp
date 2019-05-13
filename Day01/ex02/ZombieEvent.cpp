#include "ZombieEvent.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

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

std::string
ZombieEvent::getZombieType () const {

    return this->_type;
}

Zombie *
ZombieEvent::newZombie (std::string const &name) {

    return new Zombie(name, this->_type);
}

void
ZombieEvent::randomChump () {

    Zombie chump = Zombie(names[rand() % names->length()], this->_type);
    chump.announce();
}

void
ZombieEvent::setZombieType (std::string const &type) {

    this->_type = type;
}
