#include "StripMiner.hpp"
#include <iostream>

void
StripMiner::mine(IAsteroid *asteroid) {

    std::cout << "* strip mining ... got " << asteroid->beMined() << " ! *" << std::endl;
}
