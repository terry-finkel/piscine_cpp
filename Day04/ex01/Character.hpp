#ifndef DAY04_EX01_CHARACTER_HPP
# define DAY04_EX01_CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <string>

class Character {

  public:
    explicit    Character(std::string const &);
                Character(Character const &);
    Character   &operator=(Character const &);
                ~Character();
    void        attack(Enemy *);
    void        equip(AWeapon *);
    void        recoverAP();
    int         getAP() const;
    std::string getName() const;
    AWeapon     *getWeapon() const;

  private:
                Character();
    int         _AP;
    std::string _name;
    AWeapon     *_weapon;
};

std::ostream    &operator<<(std::ostream &, Character const &);

#endif /* DAY04_EX01_CHARACTER_HPP */
