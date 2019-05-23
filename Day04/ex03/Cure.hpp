#ifndef DAY04_EX03_CURE_HPP
# define DAY04_EX03_CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

  private:
                Cure();
                Cure(Cure const &);
                ~Cure();
    Cure        &operator=(Cure const &);
    AMateria    *clone() const;

  public:
    void        use(ICharacter &) const;
};

#endif /* DAY04_EX03_CURE_HPP */
