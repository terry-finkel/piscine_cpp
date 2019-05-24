#ifndef DAY_04_EX03_ICHARACTER_HPP
# define DAY_04_EX03_ICHARACTER_HPP

# include "AMateria.hpp"
# include <string>

class ICharacter {

  public:
    virtual                     ~ICharacter() {};
    virtual AMateria *const     *getMaterias() const = 0;
    virtual std::string const   &getName() const = 0;
    virtual void                displayGear() const = 0;
    virtual void                equip(AMateria *) = 0;
    virtual void                unequip(int) = 0;
    virtual void                use(int, ICharacter &) = 0;
};

#endif /* DAY_04_EX03_ICHARACTER_HPP */
