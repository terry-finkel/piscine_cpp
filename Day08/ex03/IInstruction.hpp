#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include <vector>

class IInstruction {
public:
    virtual         ~IInstruction() {};
    virtual void    execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                            std::vector<IInstruction *>::const_iterator &, unsigned int &) const = 0;
};

#endif /* IINSTRUCTION_HPP */
