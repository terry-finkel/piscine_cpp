#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include <iostream>

int
main () {
    Character *zaz = new Character("zaz");
    std::cout << *zaz;

    Enemy   *b = new RadScorpion();
    AWeapon *pf = new PowerFist();
    AWeapon *pr = new PlasmaRifle();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;

    b = new SuperMutant();
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);
    zaz->equip(pf);
    std::cout << *zaz;
    zaz->attack(b);
    zaz->recoverAP();
    zaz->recoverAP();
    zaz->recoverAP();
    std::cout << *zaz;
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);

    return 0;
}
