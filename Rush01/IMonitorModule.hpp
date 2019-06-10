#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

class IMonitorModule {
public:
	virtual         ~IMonitorModule() {};
	virtual void	updateModule() = 0;
	virtual bool	isVisible() const = 0;
    virtual void    toggle() = 0;
};

#endif /* IMONITORMODULE_HPP */
