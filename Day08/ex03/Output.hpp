#ifndef OUTPUT_HPP
# define OUTPUT_HPP

# include "IInstruction.hpp"

class Output : public IInstruction {
public:
                Output();
                Output(Output const &);
    virtual     ~Output();
    Output      &operator=(Output const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* OUTPUT_HPP */
