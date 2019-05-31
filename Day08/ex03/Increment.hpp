#ifndef INCREMENT_HPP
# define INCREMENT_HPP

# include "IInstruction.hpp"

class Increment : public IInstruction {
public:
                Increment();
                Increment(Increment const &);
    virtual     ~Increment();
    Increment   &operator=(Increment const &);
    void        execute(std::vector<unsigned char> &, std::vector<unsigned char>::iterator &,
                        std::vector<IInstruction *>::const_iterator &, unsigned int &) const;
};

#endif /* INCREMENT_HPP */
