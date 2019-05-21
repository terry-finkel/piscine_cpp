#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <cstdlib>
#include <ctime>

#define RNJESUS (rand() % 50)

int
main () {

    std::string     cname = "ClapTrap", fname = "Oberon", nname = "Maya", sname = "Alfred";
    FragTrap        fragTrap(fname);
    FragTrap        fragTrapClone(fragTrap);

    srand(time(0));
    fragTrap.beRepaired(RNJESUS);
    fragTrap.takeDamage(RNJESUS);
    fragTrap.meleeAttack("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.rangedAttack("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.rangedAttack("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.rangedAttack("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.beRepaired(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");

    ScavTrap scavTrap(sname);
    scavTrap.challengeNewcomer(fname);
    scavTrap.beRepaired(RNJESUS);
    fragTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    scavTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    scavTrap.meleeAttack("Jack");
    scavTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    scavTrap.rangedAttack("Jack");
    scavTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap.vaulthunter_dot_exe("Jack");
    scavTrap.rangedAttack("Jack");
    fragTrap.takeDamage(RNJESUS);
    fragTrap = fragTrapClone;

    NinjaTrap ninjaTrap(nname);
    ninjaTrap.meleeAttack("Jack");
    ninjaTrap.meleeAttack("Jack");
    ninjaTrap.ninjaShoebox(fragTrap);
    ninjaTrap.ninjaShoebox(scavTrap);
    ninjaTrap.ninjaShoebox(ninjaTrap);
}
