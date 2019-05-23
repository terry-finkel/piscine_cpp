#ifndef DAY_04_EX03_CHARACTER_HPP
# define DAY_04_EX03_CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter {

  private:
    AMateria            *_materias[4];
    std::string         _name;

  public:
                        Character(std::string &);
                        Character(Character const &);
    virtual             ~Character();
    Character           &operator=(Character const &);
    std::string const   &getName() const;
    void                equip(AMateria *);
    void                unequip(int);
    void                use(int, ICharacter &);
};

#endif /* DAY_04_EX03_CHARACTER_HPP */
