#ifndef DAY03_EX00_FRAGTRAP_HPP
# define DAY03_EX00_FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap {

  public:
    explicit        FragTrap (std::string &);
                    FragTrap (FragTrap const &);
                    ~FragTrap ();
    FragTrap        &operator = (FragTrap const &);
    void            vaulthunter_dot_exe (std::string const &);

  private:
                    FragTrap ();
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_FRAGTRAP_HPP */
