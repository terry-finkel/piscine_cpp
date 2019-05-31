#include "Input.hpp"
#include <iostream>

Input::Input() {}

Input::Input(Input const &rhs) { *this = rhs; }

Input::~Input() {}

Input &
Input::operator=(Input const &rhs) {

    return *this;
}

void
Input::execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &pc,
               std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    char c;
    std::cin.get(c);
    *pc = static_cast<unsigned char>(c);
    it += 1;
}
