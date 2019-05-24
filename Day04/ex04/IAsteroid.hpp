#ifndef DAY04_EX04_IASTEROID_HPP
# define DAY04_EX04_IASTEROID_HPP

# include <string>

class DeepCoreMiner;
class StripMiner;

class IAsteroid {

  public:
    virtual             ~IAsteroid() {};
    virtual std::string beMined(DeepCoreMiner *) const = 0;
    virtual std::string beMined(StripMiner *) const = 0;
    virtual std::string getName() const = 0;
};

#endif /* DAY04_EX04_IASTEROID_HPP */
