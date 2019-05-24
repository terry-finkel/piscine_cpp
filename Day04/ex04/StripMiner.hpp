#ifndef DAY04_EX04_STRIPMINER_HPP
# define DAY04_EX04_STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

public:
    virtual     ~StripMiner() {};
    void        mine(IAsteroid *);
};

#endif /* DAY04_EX04_STRIPMINER_HPP */
