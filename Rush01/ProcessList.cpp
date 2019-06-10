#include "OsInfo.hpp"
#include "ProcessList.hpp"


ProcessList::ProcessList(void) {
	_visible = true;
}

ProcessList::~ProcessList(void) {

}

void ProcessList::updateModule(void) {
	std::string string_info = Monitor::exec("top -U $USER -l 1");
	std::string info = string_info.substr(string_info.find(':') + 2);
	this->_infos = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);

	this->_cpu_usage = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);

	this->_phy_memory = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);

	this->_disks = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);

	int id;
	while (info != "\0")
	{
		id = std::atoi(info.substr(0, info.find(' ')).c_str());
		if (id)
		{
			info = info.substr(info.find(' ') + 1);
			info = info.substr(info.find_first_not_of(' '));
			this->_process_map[id] = new Process(id, info.substr(0, info.find('\n')));
		}
		info = info.substr(info.find('\n') + 1);
	}


}

const std::string &ProcessList::getInfos() const {
	return _infos;
}

const std::string &ProcessList::getCpuUsage() const {
	return _cpu_usage;
}

const std::string &ProcessList::getPhyMemory() const {
	return _phy_memory;
}

const std::string &ProcessList::getDisks() const {
	return _disks;
}

const std::map<int, Process *> &ProcessList::getProcessMap() const {
	return _process_map;
}

bool ProcessList::isVisible() const { return _visible; }
void ProcessList::toggle() { _visible = !_visible; }




