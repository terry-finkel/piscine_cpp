#ifndef JUMPNOTZERO_HPP
# define JUMPNOTZERO_HPP

# include "IInstruction.hpp"

class JumpNotZero : public IInstruction {
public:
                JumpNotZero();
                JumpNotZero(JumpNotZero const &);
    virtual     ~JumpNotZero();
    JumpNotZero &operator=(JumpNotZero const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* JUMPNOTZERO_HPP */
