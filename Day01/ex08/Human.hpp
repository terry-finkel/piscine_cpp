#ifndef DAY01_EX08_HUMAN_HPP
# define DAY01_EX08_HUMAN_HPP

# include <iostream>

class Human {

  public:
            Human ();
            ~Human ();
    void    action (std::string const &, std::string const &);

  private:
    void    meleeAttack (std::string const &);
    void    rangedAttack (std::string const &);
    void    intimidatingShout (std::string const &);
};

#endif
