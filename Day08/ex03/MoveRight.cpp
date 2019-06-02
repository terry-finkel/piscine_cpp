#include "MoveRight.hpp"

MoveRight::MoveRight() {}

MoveRight::MoveRight(MoveRight const &rhs) { *this = rhs; }

MoveRight::~MoveRight() {}

MoveRight &
MoveRight::operator=(MoveRight const &) {

    return *this;
}

void
MoveRight::execute(std::vector<unsigned char> &mem, std::vector<unsigned char>::iterator &pc,
                    std::vector<IInstruction *>::const_iterator &it, unsigned int &) const {

    if (mem.size() == static_cast<unsigned long>(pc - mem.begin()))
        mem.push_back(0);

    pc += 1;
    it += 1;
}
