#ifndef DAY04_EX00_PEON_HPP
# define DAY04_EX00_PEON_HPP

# include "Victim.hpp"

class Peon : public Victim {

  public:
            Peon (std::string);
            Peon (const Peon &);
            ~Peon ();
    Peon    &operator = (const Peon &);
    void    getPolymorphed () const;

  private:
            Peon ();
};

#endif /* DAY04_EX00_PEON_HPP */
