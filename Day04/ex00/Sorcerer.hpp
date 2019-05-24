#ifndef DAY04_EX00_SORCERER_HPP
# define DAY04_EX00_SORCERER_HPP

# include "Victim.hpp"
# include <string>

class Sorcerer {

  private:
                Sorcerer() {};
    std::string _name;
    std::string _title;

  public:
                Sorcerer(std::string, std::string);
                Sorcerer(Sorcerer const &);
    virtual     ~Sorcerer();
    Sorcerer    &operator=(Sorcerer const &);
    std::string getName() const;
    std::string getTitle() const;
    void        polymorph(Victim const &);
};

std::ostream    &operator<<(std::ostream &, Sorcerer const &);

#endif /* DAY04_EX00_SORCERER_HPP */
