#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include "IInstruction.hpp"
# include <vector>

# define MOVELEFT '1'
# define MOVERIGHT '2'
# define INCREMENT '3'
# define DECREMENT '4'
# define OUTPUT '5'
# define INPUT '6'
# define JUMPZERO '7'
# define JUMPNOTZERO '8'

class Mindopen {
private:
    unsigned int                            _brackets;
    std::vector<unsigned char>              _memory;
    std::vector<unsigned char>::iterator    _pc;
    std::vector<IInstruction *>             _queue;
                                            Mindopen();
                                            Mindopen(Mindopen const &);
    Mindopen                                &operator=(Mindopen const &);

public:

    class InvalidToken : public std::exception {
    public:
        char const                          *what() const throw();
    };

                                            Mindopen(char const *);
    virtual                                 ~Mindopen();
};

#endif /* MINDOPEN_HPP */
