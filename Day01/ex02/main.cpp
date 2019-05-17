#include "ZombieEvent.hpp"
#include <iostream>

void
invasion (ZombieEvent &horde, std::string &type, int amount) {

    horde.setZombieType(type);
    std::cout << "Une horde de zombies " << type << "s sauvages apparait!" << std::endl;
    for (int k = 0; k < amount; k++) {
        horde.randomChump();
    }
}

int
main () {

    ZombieEvent horde;
    std::string type = "camembert";
    invasion(horde, type, 4);
    Zombie *masterCam = horde.newZombie("Master Camembert");
    masterCam->announce();
    delete masterCam;

    type = "morbier";
    invasion(horde, type, 3);
    Zombie *masterMor = horde.newZombie("Master Morbier");
    masterMor->announce();
    delete masterMor;

    type = "roquefort";
    invasion(horde, type, 7);
    Zombie *masterRoq = horde.newZombie("Master Roquefort");
    masterRoq->announce();
    delete masterRoq;
}
