#ifndef DAY04_EX01_PLASMARIFLE_HPP
# define DAY04_EX01_PLASMARIFLE_HPP

# include "AWeapon.hpp"
# include <string>

class PlasmaRifle : public AWeapon {

  public:
                    PlasmaRifle();
                    PlasmaRifle(PlasmaRifle const &);
    virtual         ~PlasmaRifle();
    PlasmaRifle     &operator=(PlasmaRifle const &);
    void            attack() const;
};

#endif /* DAY04_EX01_PLASMARIFLE_HPP */
