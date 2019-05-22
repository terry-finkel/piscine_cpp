#include "SuperTrap.hpp"
#include <cstdlib>
#include <ctime>

#define RNJESUS (rand() % 50)

int
main () {

    std::string name = "Hyperion";
    SuperTrap *superTrap = new SuperTrap(name);

    superTrap->rangedAttack("Jack");
    superTrap->meleeAttack("Jack");
    superTrap->vaulthunter_dot_exe("Jack");
    superTrap->vaulthunter_dot_exe("Jack");
    superTrap->vaulthunter_dot_exe("Jack");
    superTrap->vaulthunter_dot_exe("Jack");

    SuperTrap superTrapCopy(*superTrap);
    delete superTrap;
}
