#ifndef DAY04_EX00_PEON_HPP
# define DAY04_EX00_PEON_HPP

# include "Victim.hpp"

class Peon : public Victim {

  private:
            Peon() {};

  public:
            Peon (std::string);
            Peon (const Peon &);
    virtual ~Peon ();
    Peon    &operator = (const Peon &);
    void    getPolymorphed () const;
};

#endif /* DAY04_EX00_PEON_HPP */
