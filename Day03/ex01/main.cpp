#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

#define RNJESUS (rand() % 50)

int
main () {

    std::string     cname = "Claptrap", sname = "Alfred";
    FragTrap        clapTrap(cname);
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
    ScavTrap scavTrap(sname);
    scavTrap.challengeNewcomer("ClapTrap");
    scavTrap.beRepaired(RNJESUS);
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    scavTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    scavTrap.meleeAttack("Jack");
    scavTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    scavTrap.rangedAttack("Jack");
    scavTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    clapTrap.takeDamage(RNJESUS);
    clapTrap.vaulthunter_dot_exe("Jack");
    scavTrap.rangedAttack("Jack");
    clapTrap.takeDamage(RNJESUS);

    clapTrap = clapTrapClone;
}
