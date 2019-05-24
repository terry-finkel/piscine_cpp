#ifndef DAY03_EX00_FRAGTRAP_HPP
# define DAY03_EX00_FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public virtual ClapTrap {

  public:
    explicit        FragTrap (std::string &);
                    FragTrap (FragTrap const &);
    virtual         ~FragTrap ();
    FragTrap        &operator = (FragTrap const &);
    virtual void    vaulthunter_dot_exe (std::string const &);

  protected:
    std::string     _getIdentity () const;

  private:
                    FragTrap();
};

#endif /* DAY03_EX00_FRAGTRAP_HPP */
