#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"
# include <iostream>

class Ram : public IMonitorModule {
private:
    std::string         _maxRam;
    std::string         _usedRam;
    size_t              _sizeMax;
    size_t              _sizeUsed;
    bool                _visible;

public:
                        Ram();
                        Ram(Ram const &);
    virtual             ~Ram();
    Ram                 &operator=(Ram const &);
    std::string const   &getMaxRam() const;
    std::string const   &getUsedRam() const;
    size_t              getSizeMax() const;
    size_t              getSizeUsed() const;
    bool                isVisible() const;
    void                toggle();
    void                updateModule();
};

#endif /* RAM_HPP */
