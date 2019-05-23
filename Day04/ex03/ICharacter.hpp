#ifndef DAY_04_EX03_ICHARACTER_HPP
# define DAY_04_EX03_ICHARACTER_HPP

# include <string>

class AMateria;

class ICharacter {

  private:
    AMateria                    *_materias[4];

  public:
    virtual                     ~ICharacter();
    virtual std::string const   &getName() const = 0;
    virtual void                equip(AMateria *) = 0;
    virtual void                unequip(int) = 0;
    virtual void                use(int, ICharacter &) = 0;
};

#endif /* DAY_04_EX03_ICHARACTER_HPP */
