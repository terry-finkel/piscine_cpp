#include "StripMiner.hpp"
#include <iostream>

StripMiner::StripMiner(StripMiner const &rhs) { *this = rhs; }

StripMiner &
StripMiner::operator=(StripMiner const &) {

    return *this;
}

void
StripMiner::mine(IAsteroid *asteroid) {

    std::cout << "* strip mining ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}
