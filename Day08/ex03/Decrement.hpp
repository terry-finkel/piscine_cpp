#ifndef DECREMENT_HPP
# define DECREMENT_HPP

#include "IInstruction.hpp"

class Decrement : public IInstruction {
public:
                Decrement();
                Decrement(Decrement const &);
    virtual     ~Decrement();
    Decrement   &operator=(Decrement const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* DECREMENT_HPP */
