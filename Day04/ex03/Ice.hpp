#ifndef DAY04_EX03_ICE_HPP
# define DAY04_EX03_ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

  private:
                Ice();
                Ice(Ice const &);
                ~Ice();
    Ice         &operator=(Ice const &);
    AMateria    *clone() const;

  public:
    void        use(ICharacter &) const;
};

#endif /* DAY04_EX03_ICE_HPP */
