#include "CPUInfo.hpp"
#include "Gui.hpp"
#include "NCurses.hpp"
#include "Monitor.hpp"
#include "OHName.hpp"
#include "OsInfo.hpp"
#include "ProcessList.hpp"
#include "Ram.hpp"
#include "Time.hpp"
#include "CpuUsage.hpp"

Monitor* Monitor::_current = NULL;

Monitor::Monitor(bool gui) {

    if (gui)
        _display = new Gui();
    else
        _display = new NCurses();

    Monitor::_current = this;
    _modules.push_back(new OHName());
    _modules.push_back(new OsInfo());
    _modules.push_back(new ProcessList());
    _modules.push_back(new Time());
    _modules.push_back(new CpuUsage());
    _modules.push_back(new Ram());
    _modules.push_back(new CPUInfo());
}

Monitor::Monitor(Monitor const &rhs) { *this = rhs; }

Monitor::~Monitor() {

    for (std::vector<IMonitorModule *>::const_iterator it = _modules.begin(); it != _modules.end(); it++) {
        delete *it;
    }

    delete _display;
}

Monitor &
Monitor::operator=(Monitor const &) {

    return *this;
}

Monitor*
Monitor::getCurrent() { return Monitor::_current ; }

IMonitorModule *
Monitor::getModule( int i ) {

	return (i < 0 ? NULL : _modules[i]);
}

void
Monitor::update( void ) {
	for (std::vector<IMonitorModule *>::iterator it = _modules.begin(); it != _modules.end(); it++)
		(*it)->updateModule();
}

void
Monitor::display() {
	char c = 0;
	for (;;) {
		update();
		_display->render();
		c = getch();
		switch (c)
		{
			case 'q':
				return ;
			case '1':
				Monitor::getCurrent()->getModule(0)->toggle(); break;
			case '2':
				Monitor::getCurrent()->getModule(1)->toggle(); break;
			case '3':
				Monitor::getCurrent()->getModule(2)->toggle(); break;
			case '4':
				Monitor::getCurrent()->getModule(3)->toggle(); break;
			case '5':
				Monitor::getCurrent()->getModule(4)->toggle(); break;
			default:
				break;
		}
		if (dynamic_cast<Gui*>(_display))
			break;
	}


/*
	pid_t pid;

	for ( std::list<IMonitorModule*>::iterator it = this->_modules.begin() ; it != this->_modules.end() ; it++ )
	{
		pid = fork();
		if ( pid == 0 )
		{
			signal(SIGQUIT, sigquit);
			while (this->active())
				(*it)->updateModule();
		}
		else if ( pid < 0 )
			throw(std::exception());
	}
	while (this->active())
	{
		char c = getchar();
		if (c == 'q')
		{
			kill(pid, SIGQUIT);
			this->deactivate();
			exit(0);
		}
	}*/
}

std::string
Monitor::exec(std::string const &cmd) {

    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        throw (std::exception());

    try {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL)
            result += buffer;
    } catch (std::exception &e) {
        pclose(pipe);
        throw(e);
    }

    pclose(pipe);
    return (result);
}
