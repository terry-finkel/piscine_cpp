#ifndef DAY04_EX01_RADSCORPION_HPP
# define DAY04_EX01_RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy {

  public:
                    RadScorpion();
                    RadScorpion(RadScorpion const &);
    virtual         ~RadScorpion();
    RadScorpion     &operator=(RadScorpion const &);
    void            takeDamage(int);
};

#endif /* DAY04_EX01_RADSCORPION_HPP */
