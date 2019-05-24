#ifndef DAY04_EX01_CHARACTER_HPP
# define DAY04_EX01_CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <string>

class Character {

  private:
                Character() {};
    int         _AP;
    std::string _name;
    AWeapon     *_weapon;

  public:
    explicit    Character(std::string const &);
                Character(Character const &);
    Character   &operator=(Character const &);
    virtual     ~Character() {};
    void        attack(Enemy *);
    void        equip(AWeapon *);
    void        recoverAP();
    int         getAP() const;
    std::string getName() const;
    AWeapon     *getWeapon() const;
};

std::ostream    &operator<<(std::ostream &, Character const &);

#endif /* DAY04_EX01_CHARACTER_HPP */
