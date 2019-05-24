#ifndef DAY04_EX04_STRIPMINER_HPP
# define DAY04_EX04_STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

  public:
                StripMiner() {};
                StripMiner(StripMiner const &);
    virtual     ~StripMiner() {};
    StripMiner  &operator=(StripMiner const &);
    void        mine(IAsteroid *);
};

#endif /* DAY04_EX04_STRIPMINER_HPP */
