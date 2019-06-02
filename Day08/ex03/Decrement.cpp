#include "Decrement.hpp"

Decrement::Decrement() {}

Decrement::Decrement(Decrement const &rhs) { *this = rhs; }

Decrement::~Decrement() {}

Decrement &
Decrement::operator=(Decrement const &) {

    return *this;
}

void
Decrement::execute(std::vector<unsigned char> &mem, std::vector<unsigned char>::iterator &pc,
                    std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    if (mem.size() == static_cast<unsigned long>(pc - mem.begin()))
        mem.push_back(0);

    *pc -= 1;
    it += 1;
}
