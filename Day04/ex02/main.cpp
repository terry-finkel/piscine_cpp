#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include <iostream>

int
main () {

    ISpaceMarine    *bob = new TacticalMarine;
    ISpaceMarine    *jim = new AssaultTerminator;
    ISquad          *vlc = new Squad;

    vlc->push(bob);
    vlc->push(jim);

    for (int k = 0; k < vlc->getCount(); ++k)
    {
        ISpaceMarine* cur = vlc->getUnit(k);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    delete vlc;

    AssaultTerminator	*tyrion = new AssaultTerminator;
    ISpaceMarine		*jon = new AssaultTerminator(*tyrion);
    TacticalMarine		*arya = new TacticalMarine;
    ISpaceMarine		*sansa = new TacticalMarine(*arya);
    ISpaceMarine		*jaime = new TacticalMarine;
    ISpaceMarine		*bran = new AssaultTerminator;
    ISquad				*squad = new Squad;

    squad->push(jon);
    squad->push(sansa);
    squad->push(bran);
    squad->push(jaime);

    ISquad *squadCopy = squad;
    for (int k = 0; k < squadCopy->getCount(); ++k)
    {
        ISpaceMarine* test = squadCopy->getUnit(k);
        test->battleCry();
        test->rangedAttack();
        test->meleeAttack();
    }

    delete squadCopy;
    delete tyrion;
    delete arya;
    return 0;
}
