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
    clapTrapClone.beRepaired(RNJESUS);
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.meleeAttack("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.rangedAttack("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.rangedAttack("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.rangedAttack("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.beRepaired(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);
    clapTrapClone.vaulthunter_dot_exe("Jack");
    clapTrapClone.takeDamage(RNJESUS);

    clapTrap = clapTrapClone;
}
