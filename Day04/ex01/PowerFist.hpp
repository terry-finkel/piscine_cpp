#ifndef DAY04_EX01_POWERFIST_HPP
# define DAY04_EX01_POWERFIST_HPP

# include "AWeapon.hpp"
# include <string>

class PowerFist : public AWeapon {

  public:
                    PowerFist();
                    PowerFist(PowerFist const &);
    virtual         ~PowerFist();
    PowerFist       &operator=(PowerFist const &);
    void            attack() const;
};

#endif /* DAY04_EX01_POWERFIST_HPP */
