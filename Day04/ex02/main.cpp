#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int
main () {

    ISpaceMarine    *bob = new TacticalMarine;
    ISpaceMarine    *jim = new AssaultTerminator;
    ISquad          *vlc = new Squad;

    vlc->push(bob);
    vlc->push(jim);

    for (int k = 0; k < vlc->getCount(); k++) {
        ISpaceMarine *cur = vlc->getUnit(k);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    delete vlc;
    return 0;
}
