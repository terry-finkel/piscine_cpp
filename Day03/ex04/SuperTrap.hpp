#ifndef DAY03_EX00_SUPERTRAP_HPP
# define DAY03_EX00_SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {

  public:
    explicit        SuperTrap (std::string &);
                    SuperTrap (SuperTrap const &);
    virtual         ~SuperTrap ();
    SuperTrap       &operator = (SuperTrap const &);
    void            meleeAttack (std::string const &) const override;
    void            ninjaShoebox (ClapTrap const &) const override;
    void            ninjaShoebox (FragTrap &) override;
    void            ninjaShoebox (NinjaTrap &) override;
    void            ninjaShoebox (ScavTrap &) override;
    void            rangedAttack (std::string const &) const override;
    void            vaulthunter_dot_exe (std::string const &) override;

private:
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_SUPERTRAP_HPP */
