#ifndef DAY01_EX02_ZOMBIE_HPP
# define DAY01_EX02_ZOMBIE_HPP

# include <string>

class Zombie {

  public:
                Zombie (std::string, std::string);
    void        announce () const;

  private:
    std::string _name,
                _type;
};

#endif /* DAY01_EX02_ZOMBIE_HPP */
