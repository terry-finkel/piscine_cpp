#ifndef OHNAME_HPP
# define OHNAME_HPP

# include "IMonitorModule.hpp"
# include <string>

class OHName : public IMonitorModule {
private:
    std::string         _hostname;
    std::string         _username;
    bool				_visible;

public:
                        OHName();
                        OHName(OHName const &);
    virtual             ~OHName();
    OHName              &operator=(OHName const &);
    std::string	const   &getHostname() const;
    std::string const   &getUsername() const;
    virtual bool		isVisible() const;
    virtual void		toggle();
    void		        updateModule();
};

#endif /* OHNAME_HPP */
