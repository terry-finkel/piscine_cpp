#ifndef DAY04_EX04_ASTEROBOCAL_HPP
# define DAY04_EX04_ASTEROBOCAL_HPP

# include "IAsteroid.hpp"
# include <string>

class AsteroBocal : public IAsteroid {

  public:
                    AsteroBocal() {};
                    AsteroBocal(AsteroBocal const &);
    virtual         ~AsteroBocal() {};
    AsteroBocal     &operator=(AsteroBocal const &);
    std::string     beMined(DeepCoreMiner *laser) const;
    std::string     beMined(StripMiner *laser) const;
    std::string     getName() const;
};

#endif /* DAY04_EX04_ASTEROBOCAL_HPP */
