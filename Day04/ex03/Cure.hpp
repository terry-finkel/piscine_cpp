#ifndef DAY04_EX03_CURE_HPP
# define DAY04_EX03_CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

  public:
                Cure();
                Cure(Cure const &);
    virtual     ~Cure() {};
    Cure        &operator=(Cure const &);
    AMateria    *clone() const;
    void        use(ICharacter &);
};

#endif /* DAY04_EX03_CURE_HPP */
