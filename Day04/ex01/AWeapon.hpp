#ifndef DAY04_EX01_AWEAPON_HPP
# define DAY04_EX01_AWEAPON_HPP

# include <string>

class AWeapon {

  private:
    int             _APCost;
    int             _damage;
    std::string     _name;

  protected:
                    AWeapon() {};

  public:
                    AWeapon(std::string const &, int, int);
                    AWeapon(AWeapon const &);
    virtual         ~AWeapon() {};
    AWeapon         &operator=(AWeapon const &);
    virtual void    attack() const = 0;
    int             getAPCost() const;
    int             getDamage() const;
    std::string     getName() const;
};

#endif /* DAY04_EX01_AWEAPON_HPP */
