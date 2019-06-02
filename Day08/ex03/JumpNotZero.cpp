#include "JumpNotZero.hpp"
#include "JumpZero.hpp"

JumpNotZero::JumpNotZero() {}

JumpNotZero::JumpNotZero(JumpNotZero const &rhs) { *this = rhs; }

JumpNotZero::~JumpNotZero() {}

JumpNotZero &
JumpNotZero::operator=(JumpNotZero const &) {

    return *this;
}

void
JumpNotZero::execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &pc,
                     std::vector<IInstruction *>::const_iterator &it, unsigned int &jz) const {

    if (*pc) {
        jz += 1;
        while (jz) {
            it -= 1;
            if (dynamic_cast<JumpZero *>(*it))
                jz -= 1;
            else if (dynamic_cast<JumpNotZero *>(*it))
                jz += 1;
        }
    }

    it += 1;
}
