#ifndef CPUUSAGE_HPP
# define CPUUSAGE_HPP

# include "IMonitorModule.hpp"
# include "Monitor.hpp"
# include <string>


class CpuUsage: public IMonitorModule {
private:
    double              _cpu;
    double              _user;
    bool                _visible;

public:
	                    CpuUsage();
	                    CpuUsage(CpuUsage const &);
	virtual             ~CpuUsage();
	CpuUsage            &operator=(CpuUsage const &);
	void		        updateModule();
	double              getCPU() const;
    double              getUser() const;
    virtual bool        isVisible() const;
    virtual void        toggle();
};

#endif /* CpuUsage_HPP */
