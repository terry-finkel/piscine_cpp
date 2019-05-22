#ifndef DAY04_EX01_SUPERMUTANT_HPP
# define DAY04_EX01_SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {

  public:
                    SuperMutant();
                    SuperMutant(SuperMutant const &);
    virtual         ~SuperMutant();
    SuperMutant     &operator=(SuperMutant const &);
    void            takeDamage(int);
};

#endif /* DAY04_EX01_SUPERMUTANT_HPP */
