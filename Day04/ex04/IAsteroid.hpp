#ifndef DAY04_EX04_IASTEROID_HPP
# define DAY04_EX04_IASTEROID_HPP

# include <string>

class AsteroBocal;
class BocalSteroid;

class IAsteroid {

  public:
    virtual             ~IAsteroid() {};
    virtual std::string beMined(AsteroBocal *) const = 0;
    virtual std::string beMined(BocalSteroid *) const = 0;
    virtual std::string getName() const = 0;
};

#endif /* DAY04_EX04_IASTEROID_HPP */
