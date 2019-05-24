#ifndef DAY04_EX04_IMININGLASER_HPP
# define DAY04_EX04_IMININGLASER_HPP

# include "IAsteroid.hpp"

class IMiningLaser {

  public:
    virtual         ~IMiningLaser() {};
    virtual void    mine(IAsteroid *) = 0;
};

#endif /* DAY04_EX04_IMININGLASER_HPP */
