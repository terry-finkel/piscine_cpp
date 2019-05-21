#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

#define RNJESUS (rand() % 50)

int
main () {

    std::string     name = "Claptrap";
    FragTrap        clapTrap(name);
    FragTrap        clapTrapClone(clapTrap);

    srand(time(0));
    clapTrap.beRepaired(RNJESUS);
    clapTrap.takeDamage(RNJESUS);
    clapTrap.meleeAttack("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.rangedAttack("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.rangedAttack("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.rangedAttack("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.beRepaired(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);

    clapTrap = clapTrapClone;
}
