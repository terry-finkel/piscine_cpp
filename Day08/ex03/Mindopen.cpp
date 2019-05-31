#include "Decrement.hpp"
#include "Increment.hpp"
#include "Input.hpp"
#include "JumpNotZero.hpp"
#include "JumpZero.hpp"
#include "MoveLeft.hpp"
#include "MoveRight.hpp"
#include "Mindopen.hpp"
#include "Output.hpp"
#include <fstream>
#include <iostream>

Mindopen::Mindopen() {}

Mindopen::Mindopen(char const *filename) : _brackets(0), _memory(1, 0), _pc(_memory.begin()), _queue() {

    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("couldn't open file");

    char c;
    while (file.get(c)) {
        switch (c) {
            case MOVELEFT:
                _queue.push_back(new MoveLeft());
                break;
            case MOVERIGHT:
                _queue.push_back(new MoveRight());
                break;
            case INCREMENT:
                _queue.push_back(new Increment());
                break;
            case DECREMENT:
                _queue.push_back(new Decrement());
                break;
            case OUTPUT:
                _queue.push_back(new Output());
                break;
            case INPUT:
                _queue.push_back(new Input());
                break;
            case JUMPZERO:
                _queue.push_back(new JumpZero());
                break;
            case JUMPNOTZERO:
                _queue.push_back(new JumpNotZero());
                break;
            default:
                if (isspace(c))
                    break;
                char buff[1];
                buff[0] = static_cast<char>(c);
                throw Mindopen::InvalidToken();
        }
    }

    /* Don't clear instructions yet because of jump tokens. */
    for (std::vector<IInstruction *>::const_iterator it = _queue.begin(); it != _queue.end(); ) {
        (*it)->execute(_memory, _pc, it, _brackets);
    }

    /* Cleanup. */
    for (std::vector<IInstruction *>::const_iterator it = _queue.begin(); it != _queue.end(); it++) {
        delete *it;
    }
}

Mindopen::Mindopen(Mindopen const &rhs) { *this = rhs; }

Mindopen::~Mindopen() {}

Mindopen &
Mindopen::operator=(Mindopen const &rhs) {

    return *this;
}

char const *
Mindopen::InvalidToken::what() const throw() {

    return "invalid token";
}
