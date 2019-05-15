#ifndef DAY01_EX06_WEAPON_HPP
# define DAY01_EX06_WEAPON_HPP

# include <string>

class Weapon {

  public:
    explicit            Weapon (std::string);
                        ~Weapon ();
    const std::string   &getType () const;
    void                setType (std::string type);

  private:
    std::string         _type;
};

#endif /* DAY01_EX06_WEAPON_HPP */
