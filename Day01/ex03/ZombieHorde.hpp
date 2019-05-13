#ifndef DAY01_EX03_ZOMBIEHORDE_HPP
# define DAY01_EX03_ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

  public:
    explicit    ZombieHorde (int);
                ~ZombieHorde ();
    void        announce () const;

  private:
    int         _amount;
    Zombie      *_horde;
};

#endif /* DAY01_EX03_ZOMBIEHORDE_HPP */
