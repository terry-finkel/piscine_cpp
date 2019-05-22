#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <iostream>


int
main () {

    Sorcerer    robert("Robert", "the Magnificient");
    Victim      jim("Jimmy");
    Peon        joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

    return 0;
}
