#ifndef DAY03_EX00_CLAPTRAP_HPP
# define DAY03_EX00_CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

  public:
    explicit            ClapTrap (std::string &);
                        ClapTrap (ClapTrap const &);
                        ~ClapTrap ();
    ClapTrap            &operator = (ClapTrap const &);
    void                beRepaired (unsigned int);
    void                meleeAttack (std::string const &);
    void                rangedAttack (std::string const &);
    void                takeDamage (unsigned int);

  protected:
                        ClapTrap ();
    unsigned int        _HP;
    unsigned int        _maxHP;
    unsigned int        _EP;
    unsigned int        _maxEP;
    unsigned int        _level;
    std::string         _name;
    unsigned int        _meleeDMG;
    unsigned int        _rangedDMG;
    unsigned int        _armor;
    virtual std::string _getIdentity () const;
};

#endif /* DAY03_EX00_CLAPTRAP_HPP */
