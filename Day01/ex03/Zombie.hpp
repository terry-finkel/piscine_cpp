#ifndef DAY01_EX02_ZOMBIE_HPP
# define DAY01_EX02_ZOMBIE_HPP

# include <string>

class Zombie {

  public:
                Zombie ();
                ~Zombie ();
    void        announce () const;
    void        setName (std::string &);
    void        setType (std::string &);

  private:
    std::string _name,
                _type;
};

#endif /* DAY01_EX02_ZOMBIE_HPP */
