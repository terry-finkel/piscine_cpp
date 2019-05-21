#ifndef DAY03_EX00_SUPERTRAP_HPP
# define DAY03_EX00_SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {

  public:
    explicit        SuperTrap (std::string &);
                    SuperTrap (SuperTrap const &);
                    ~SuperTrap ();
    SuperTrap       &operator = (SuperTrap const &);

  private:
                    SuperTrap ();
    std::string     _getIdentity () const override;
};

#endif /* DAY03_EX00_SUPERTRAP_HPP */
