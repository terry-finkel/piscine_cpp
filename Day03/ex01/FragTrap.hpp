#ifndef DAY03_EX00_FRAGTRAP_HPP
# define DAY03_EX00_FRAGTRAP_HPP

# include <iostream>

class FragTrap {

  public:
    explicit        FragTrap (std::string &);
                    FragTrap (FragTrap const &);
                    ~FragTrap ();
    FragTrap        &operator = (FragTrap const &);
    void            beRepaired (unsigned int);
    void            meleeAttack (std::string const &);
    void            rangedAttack (std::string const &);
    void            takeDamage (unsigned int);
    void            vaulthunter_dot_exe (std::string const &);

  private:
                    FragTrap ();
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

#endif /* DAY03_EX00_FRAGTRAP_HPP */
