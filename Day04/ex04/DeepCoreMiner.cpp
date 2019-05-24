#include "DeepCoreMiner.hpp"
#include <iostream>

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &rhs) { *this = rhs; }

DeepCoreMiner &
DeepCoreMiner::operator=(DeepCoreMiner const &) {

    return *this;
}

void
DeepCoreMiner::mine(IAsteroid *asteroid) {

    std::cout << "* mining deep ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}
