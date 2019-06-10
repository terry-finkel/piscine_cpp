#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <ctime>
#include <string>
#include <time.h>
#include <chrono>
#include <iostream>

class Process
{
public:
	Process( void );
	Process( int id, std::string src );
	~Process( void );

	void	updateInfos( std::string src );

	unsigned int getId() const;
	const std::string &getCommand() const;
	float getCpuUsage() const;
	std::string getTime() const;
	const std::string &getState() const;
	unsigned long getMemory() const;
	double getCpuMe() const;
	double getCpuOthrs() const;


private:
	unsigned int	_id;
	std::string		_command;
	float			_cpu_usage;
	std::string		_time;
	std::string		_state;
	unsigned long 	_memory;
	double			_cpu_me;
	double			_cpu_othrs;
};




#endif

