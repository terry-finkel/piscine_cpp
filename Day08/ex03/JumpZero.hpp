#ifndef JUMPZERO_HPP
# define JUMPZERO_HPP

# include "IInstruction.hpp"

class JumpZero : public IInstruction {
public:
                JumpZero();
                JumpZero(JumpZero const &);
    virtual     ~JumpZero();
    JumpZero    &operator=(JumpZero const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* JUMPZERO_HPP */
