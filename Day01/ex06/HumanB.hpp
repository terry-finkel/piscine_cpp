#ifndef DAY01_EX06_HUMANB_HPP
# define DAY01_EX06_HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {

  public:
    explicit        HumanB (std::string);
                    ~HumanB ();
    void            attack () const;
    void            setWeapon (Weapon &);

  private:
    std::string     _name;
    const Weapon    *_weapon;
};

#endif /* DAY01_EX06_HUMANB_HPP */
