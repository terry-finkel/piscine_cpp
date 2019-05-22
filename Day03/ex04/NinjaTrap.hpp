#ifndef DAY03_EX00_NINJATRAP_HPP
# define DAY03_EX00_NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class NinjaTrap : public virtual ClapTrap {

  public:
    explicit        NinjaTrap (std::string &);
                    NinjaTrap (NinjaTrap const &);
    virtual         ~NinjaTrap ();
    NinjaTrap       &operator = (NinjaTrap const &);
    virtual void    ninjaShoebox (ClapTrap const &) const;
    virtual void    ninjaShoebox (FragTrap &);
    virtual void    ninjaShoebox (NinjaTrap &);
    virtual void    ninjaShoebox (ScavTrap &);

  protected:
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_NINJATRAP_HPP */
