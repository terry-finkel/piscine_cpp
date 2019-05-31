#ifndef MOVELEFT_HPP
# define MOVELEFT_HPP

# include "IInstruction.hpp"

class MoveLeft : public IInstruction {
public:
                MoveLeft();
                MoveLeft(MoveLeft const &);
    virtual     ~MoveLeft();
    MoveLeft    &operator=(MoveLeft const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* MOVELEFT_HPP */
