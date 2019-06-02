#include "Increment.hpp"

Increment::Increment() {}

Increment::Increment(Increment const &rhs) { *this = rhs; }

Increment::~Increment() {}

Increment &
Increment::operator=(Increment const &) {

    return *this;
}

void
Increment::execute(std::vector<unsigned char> &mem, std::vector<unsigned char>::iterator &pc,
                   std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    if (mem.size() == static_cast<unsigned long>(pc - mem.begin()))
        mem.push_back(0);

    *pc += 1;
    it += 1;
}
