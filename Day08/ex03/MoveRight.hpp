#ifndef MOVERIGHT_HPP
# define MOVERIGHT_HPP

# include "IInstruction.hpp"

class MoveRight : public IInstruction {
public:
                MoveRight();
                MoveRight(MoveRight const &);
    virtual     ~MoveRight();
    MoveRight   &operator=(MoveRight const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* MOVERIGHT_HPP */
