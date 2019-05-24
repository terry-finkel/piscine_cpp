#ifndef DAY04_EX04_MININGBARGE_HPP
# define DAY04_EX04_MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

# define LASERS (4)

class MiningBarge {

  private:
    IMiningLaser        *_lasers[LASERS];

  public:
                        MiningBarge();
                        MiningBarge(MiningBarge const &);
    virtual             ~MiningBarge() {};
    MiningBarge         &operator=(MiningBarge const &);
    void                equip(IMiningLaser *);
    IMiningLaser *const *getLasers() const;
    void                mine(IAsteroid *) const;
};

#endif /* DAY04_EX04_MININGBARGE_HPP */
