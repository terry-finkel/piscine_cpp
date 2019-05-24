#ifndef DAY04_EX04_ASTEROBOCAL_HPP
# define DAY04_EX04_ASTEROBOCAL_HPP

# include "IAsteroid.hpp"
# include <string>

class AsteroBocal : public IAsteroid {

  public:
    virtual         ~AsteroBocal() {};
    std::string     beMined(AsteroBocal *) const;
    std::string     getName() const;
};

#endif /* DAY04_EX04_ASTEROBOCAL_HPP */
