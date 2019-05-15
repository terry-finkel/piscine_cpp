#include "Brain.hpp"

Brain::Brain () {}

Brain::~Brain () {}

std::string
Brain::identify () const {

    std::ostringstream oss;
    oss << this;
    return oss.str();
}
