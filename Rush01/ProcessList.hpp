#ifndef PROCESSLIST_HPP
#define PROCESSLIST_HPP

#include "IMonitorModule.hpp"

#include "Process.hpp"
#include "Monitor.hpp"
#include <map>


class ProcessList: public IMonitorModule
{
public:
	ProcessList( void );
	virtual ~ProcessList( void );

	virtual void		updateModule( void );


private:
	std::string				_infos;
public:
	const std::string &getInfos() const;

	const std::string &getCpuUsage() const;

	const std::string &getPhyMemory() const;

	const std::string &getDisks() const;

	const std::map<int, Process *> &getProcessMap() const;

	virtual bool		isVisible() const;
	virtual void		toggle();

private:
	std::string				_cpu_usage;
	std::string				_phy_memory;
	std::string				_disks;
	bool					_visible;

	std::map<int, Process*> _process_map;

};

#endif // ProcessList_HPP
