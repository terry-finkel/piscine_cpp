#include "MoveLeft.hpp"

MoveLeft::MoveLeft() {}

MoveLeft::MoveLeft(MoveLeft const &rhs) { *this = rhs; }

MoveLeft::~MoveLeft() {}

MoveLeft &
MoveLeft::operator=(MoveLeft const &rhs) {

    return *this;
}

void
MoveLeft::execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &pc,
                  std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    pc -= 1;
    it += 1;
}
