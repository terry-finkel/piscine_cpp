#ifndef DAY03_EX00_SCAVTRAP_HPP
# define DAY03_EX00_SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {

  protected:
                    ScavTrap() {};
    std::string     _getIdentity () const;

  public:
    explicit        ScavTrap (std::string &);
                    ScavTrap (ScavTrap const &);
    virtual         ~ScavTrap ();
    ScavTrap        &operator = (ScavTrap const &);
    void            challengeNewcomer (std::string const &);
};

#endif /* DAY03_EX00_SCAVTRAP_HPP */
