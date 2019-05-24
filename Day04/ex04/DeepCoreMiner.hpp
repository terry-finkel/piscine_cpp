#ifndef DAY04_EX04_DEEPCOREMINER_HPP
# define DAY04_EX04_DEEPCOREMINER_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {

  public:
                    DeepCoreMiner() {};
                    DeepCoreMiner(DeepCoreMiner const &);
    virtual         ~DeepCoreMiner() {};
    DeepCoreMiner   &operator=(DeepCoreMiner const &);
    void            mine(IAsteroid *);
};

#endif /* DAY04_EX04_DEEPCOREMINER_HPP */
