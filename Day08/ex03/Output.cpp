#include "Output.hpp"
#include <iostream>

Output::Output() {}

Output::Output(Output const &rhs) { *this = rhs; }

Output::~Output() {}

Output &
Output::operator=(Output const &) {

    return *this;
}

void
Output::execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &pc,
                std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    std::cout << *pc;
    it += 1;
}
