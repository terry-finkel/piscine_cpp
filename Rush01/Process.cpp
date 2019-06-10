
#include "Process.hpp"

Process::Process(void) {

}

Process::~Process(void) {

}

Process::Process(int id, std::string src): _id(id) {
	this->updateInfos(src);
}

void Process::updateInfos(std::string src) {
	std::string	info = src;
	this->_command = info.substr(0, info.find(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_cpu_usage = std::atof(info.substr(0, info.find(' ')).c_str());

	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_time = info.substr(0, info.find(' '));

	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_memory = std::atol(info.substr(0, info.find('+')).c_str());

	char c = info[info.find('+') - 1];
	if ( c == 'G' )
		this->_memory *= 1000000000;
	if ( c == 'M' )
		this->_memory *= 1000000;
	else if ( c == 'K' )
		this->_memory *= 1000;

	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_state = info.substr(0, info.find(' '));

	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));
	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_cpu_me = std::atof(info.substr(0, info.find(' ')).c_str());

	info = info.substr(info.find(' ') + 1);
	info = info.substr(info.find_first_not_of(' '));

	this->_cpu_othrs = std::atof(info.substr(0, info.find(' ')).c_str());

}

std::string Process::getTime() const {
	return _time;
}

unsigned int Process::getId() const {
	return _id;
}

const std::string &Process::getCommand() const {
	return _command;
}

float Process::getCpuUsage() const {
	return _cpu_usage;
}

const std::string &Process::getState() const {
	return _state;
}

unsigned long Process::getMemory() const {
	return _memory;
}

double Process::getCpuMe() const {
	return _cpu_me;
}

double Process::getCpuOthrs() const {
	return _cpu_othrs;
}

