#include "JumpNotZero.hpp"
#include "JumpZero.hpp"

JumpZero::JumpZero() {}

JumpZero::JumpZero(JumpZero const &rhs) { *this = rhs; }

JumpZero::~JumpZero() {}

JumpZero &
JumpZero::operator=(JumpZero const &rhs) {

    return *this;
}

void
JumpZero::execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &pc,
                  std::vector<IInstruction *>::const_iterator &it, unsigned int &jz) const {

    if (*pc == 0) {
        jz += 1;
        while (jz) {
            it += 1;
            if (dynamic_cast<JumpZero *>(*it))
                jz += 1;
            else if (dynamic_cast<JumpNotZero *>(*it))
                jz -= 1;
        }
    }

    it += 1;
}
