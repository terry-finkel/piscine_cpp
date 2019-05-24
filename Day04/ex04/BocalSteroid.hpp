#ifndef DAY04_EX04_BOCALSTEROID_HPP
# define DAY04_EX04_BOCALSTEROID_HPP

# include "IAsteroid.hpp"
# include <string>

class BocalSteroid : public IAsteroid {

public:
                    BocalSteroid() {};
                    BocalSteroid(BocalSteroid const &);
    virtual         ~BocalSteroid() {};
    BocalSteroid    &operator=(BocalSteroid const &);
    std::string     beMined(DeepCoreMiner *laser) const;
    std::string     beMined(StripMiner *laser) const;
    std::string     getName() const;
};

#endif /* DAY04_EX04_BOCALSTEROID_HPP */
