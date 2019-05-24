#include "DeepCoreMiner.hpp"
#include <iostream>

void
DeepCoreMiner::mine(IAsteroid *asteroid) {

    std::cout << "* mining deep ... got " << asteroid->beMined(asteroid) << " ! *" << std::endl;
}
