#ifndef INPUT_HPP
# define INPUT_HPP

# include "IInstruction.hpp"

class Input : public IInstruction {
public:
                Input();
                Input(Input const &);
    virtual     ~Input();
    Input       &operator=(Input const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* INPUT_HPP */
