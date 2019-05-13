#ifndef DAY01_EX02_ZOMBIEEVENT_HPP
# define DAY01_EX02_ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <string>

class ZombieEvent {

  public:
    std::string getZombieType () const;
    Zombie      *newZombie (std::string const &);
    void        randomChump ();
    void        setZombieType (std::string const &);

  private:
    std::string _type;
};

#endif /* DAY01_EX02_ZOMBIEEVENT_HPP */
