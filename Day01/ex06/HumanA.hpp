#ifndef DAY01_EX06_HUMANA_HPP
# define DAY01_EX06_HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {

  public:
                    HumanA (std::string, const Weapon &);
                    ~HumanA ();
    void            attack () const;

  private:
    std::string     _name;
    const Weapon    &_weapon;
};

#endif /* DAY01_EX06_HUMANA_HPP */
