#ifndef OSINFO_HPP
# define OSINFO_HPP

# include "IMonitorModule.hpp"
# include <string>


class OsInfo: public IMonitorModule {
private:
    std::string         _machine;
    std::string         _release;
    std::string         _sysname;
    std::string         _version;
    bool                _visible;

public:
	                    OsInfo();
	                    OsInfo(OsInfo const &);
	virtual             ~OsInfo();
	OsInfo              &operator=(OsInfo const &);
	void		        updateModule();
	std::string const   &getMachine() const;
    std::string const   &getRelease() const;
    std::string const   &getSysname() const;
    std::string const   &getVersion() const;
    virtual bool        isVisible() const;
    virtual void        toggle();

};

#endif /* OSINFO_HPP */
