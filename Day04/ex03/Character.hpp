#ifndef DAY_04_EX03_CHARACTER_HPP
# define DAY_04_EX03_CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter {

  private:
                        Character() {};
    AMateria            *_materias[MAX];
    std::string         _name;
    void                _deleteMaterias();

  public:
                        Character(std::string);
                        Character(Character const &);
    virtual             ~Character();
    Character           &operator=(Character const &);
    void                displayGear() const;
    void                equip(AMateria *);
    AMateria *const     *getMaterias() const;
    std::string const   &getName() const;
    void                unequip(int);
    void                use(int, ICharacter &);
};

#endif /* DAY_04_EX03_CHARACTER_HPP */
