#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator() {

    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &rhs) { *this = rhs; }

AssaultTerminator::~AssaultTerminator() {

    std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator &
AssaultTerminator::operator=(AssaultTerminator const &rhs) {

    static_cast<void>(rhs);
    return *this;
}

void
AssaultTerminator::battleCry() const {

    std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

ISpaceMarine*
AssaultTerminator::clone() const {

    return new AssaultTerminator(*this);
}

void
AssaultTerminator::meleeAttack() const {

    std::cout << "* attacks with chainfists *" << std::endl;
}

void
AssaultTerminator::rangedAttack() const {

    std::cout << "* does nothing *" << std::endl;
}
