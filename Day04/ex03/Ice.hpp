#ifndef DAY04_EX03_ICE_HPP
# define DAY04_EX03_ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

  public:
                Ice();
                Ice(Ice const &);
                ~Ice();
    Ice         &operator=(Ice const &);
    AMateria    *clone() const;
    void        use(ICharacter &);
};

#endif /* DAY04_EX03_ICE_HPP */
