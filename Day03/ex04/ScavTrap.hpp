#ifndef DAY03_EX00_SCAVTRAP_HPP
# define DAY03_EX00_SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {

  public:
    explicit        ScavTrap (std::string &);
                    ScavTrap (ScavTrap const &);
    virtual         ~ScavTrap ();
    ScavTrap        &operator = (ScavTrap const &);
    void            challengeNewcomer (std::string const &);

  private:
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_SCAVTRAP_HPP */
