#ifndef DAY03_EX00_SCAVTRAP_HPP
# define DAY03_EX00_SCAVTRAP_HPP

# include <iostream>

class ScavTrap {

  public:
    explicit        ScavTrap (std::string &);
                    ScavTrap (ScavTrap const &);
                    ~ScavTrap ();
    ScavTrap        &operator = (ScavTrap const &);
    void            beRepaired (unsigned int);
    void            challengeNewcomer (std::string const &);
    void            meleeAttack (std::string const &);
    void            rangedAttack (std::string const &);
    void            takeDamage (unsigned int);

  private:
                    ScavTrap ();
    unsigned int    _HP;
    unsigned int    _maxHP;
    unsigned int    _EP;
    unsigned int    _maxEP;
    unsigned int    _level;
    std::string     _name;
    unsigned int    _meleeDMG;
    unsigned int    _rangedDMG;
    unsigned int    _armor;
    std::string     _getIdentity () const;
};

#endif /* DAY03_EX00_SCAVTRAP_HPP */
