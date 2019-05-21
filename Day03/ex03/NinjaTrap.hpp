#ifndef DAY03_EX00_NINJATRAP_HPP
# define DAY03_EX00_NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class NinjaTrap : public ClapTrap {

  public:
    explicit        NinjaTrap (std::string &);
                    NinjaTrap (NinjaTrap const &);
                    ~NinjaTrap ();
    NinjaTrap       &operator = (NinjaTrap const &);
    void            ninjaShoebox (ClapTrap const &);
    void            ninjaShoebox (FragTrap &);
    void            ninjaShoebox (NinjaTrap &);
    void            ninjaShoebox (ScavTrap &);

  private:
                    NinjaTrap ();
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_NINJATRAP_HPP */
