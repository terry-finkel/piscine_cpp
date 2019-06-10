#include "NCurses.hpp"
#include <iostream>

NCurses::NCurses() {

	setlocale(LC_ALL, "");
	initscr();
	nodelay(stdscr, TRUE);
	cbreak();
	noecho();
	start_color();
	curs_set(0);
	
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	if (LINES < 30 || COLS < 30)
		throw NCurses::WinTooSmallException();
	_win1 = newwin(4, 40, 0, 0);
	_win2 = newwin(4, 40, 0, 40);
	_win3 = newwin(4, 80, 4, 0);
	_win4 = newwin(7, 80, 8, 0);
	_win5 = newwin(50, 80, 15, 0);
}

NCurses::NCurses(NCurses const &rhs) { *this = rhs; }

NCurses::~NCurses()
{
	delwin(_win1);
	delwin(_win2);
	delwin(_win3);
	delwin(_win4);
	delwin(_win5);
	endwin();
}

NCurses &
NCurses::operator=(NCurses const &) {

	return *this;
}

void
loading_bar(WINDOW* win, size_t line, size_t col, size_t total, size_t pc, size_t user)
{
	pc = pc * 50 / total;
	user = user * 50 / total;
	
	for (size_t i = 0; i < user; ++i)
	{
		wattron(win, COLOR_PAIR(1));
		mvwprintw(win, line, col+i, "█");
		wattroff(win, COLOR_PAIR(1));
	}
	for (size_t i = user; i < pc; ++i)
	{
		wattron(win, COLOR_PAIR(1));
		mvwprintw(win, line, col+i, "░");
		wattroff(win, COLOR_PAIR(1));
	}
	for (size_t i = pc; i < 50; ++i)
	{
		wattron(win, COLOR_PAIR(0));
		mvwprintw(win, line, col+i, "░");
		wattroff(win, COLOR_PAIR(0));
	}
}


void
NCurses::ft_win1() {

	OHName *oh_name = dynamic_cast<OHName*>(Monitor::getCurrent()->getModule(0));

	mvwprintw(_win1, 1, 2, "Hostname: ");
	mvwprintw(_win1, 1, 14, oh_name->getHostname().c_str());
	mvwprintw(_win1, 2, 2, "Username: ");
	mvwprintw(_win1, 2, 14, oh_name->getUsername().c_str());
}

void
NCurses::ft_win2() {

	Time *time = dynamic_cast<Time*>(Monitor::getCurrent()->getModule(3));

	mvwprintw(_win2, 1, 2, "Date: ");
	mvwprintw(_win2, 1, 14, time->getDate().c_str());
	mvwprintw(_win2, 2, 2, "Time: ");
	mvwprintw(_win2, 2, 14, time->getTime().c_str());
}

void
NCurses::ft_win3() {

	OsInfo *os_info = dynamic_cast<OsInfo*>(Monitor::getCurrent()->getModule(1));

	mvwprintw(_win3, 1, 2, "Machine: ");
	mvwprintw(_win3, 1, 12, os_info->getMachine().c_str());
	mvwprintw(_win3, 2, 2, "Release: ");
	mvwprintw(_win3, 2, 12, os_info->getRelease().c_str());
	mvwprintw(_win3, 1, 23, "Sysname: ");
	mvwprintw(_win3, 1, 33, os_info->getSysname().c_str());
	mvwprintw(_win3, 2, 23, "Version: ");
	mvwprintw(_win3, 2, 33, os_info->getVersion().c_str());
}

void
NCurses::ft_win4() {

	CpuUsage *	cpu_usage = dynamic_cast<CpuUsage*>(Monitor::getCurrent()->getModule(4));
	Ram *		ram = dynamic_cast<Ram*>(Monitor::getCurrent()->getModule(5));
	mvwprintw(_win4, 2, 4, "Cpu Usage: ");
	loading_bar(_win4, 2, 24, 100, cpu_usage->getCPU(), cpu_usage->getUser());
	mvwprintw(_win4, 4, 4, "Memory Usage: ");
	loading_bar(_win4, 4, 24, ram->getSizeMax(), ram->getSizeUsed(), 0);

}

void
NCurses::ft_win5() {

	ProcessList *process_list = dynamic_cast<ProcessList*>(Monitor::getCurrent()->getModule(2));
	int			index = 1;

	for (std::map<int,Process*>::const_iterator it = process_list->getProcessMap().begin() ; it != process_list->getProcessMap().end() ; it++, index++) {
		mvwprintw(_win5, index, 1, std::to_string(it->first).c_str());
		mvwprintw(_win5, index, 8, it->second->getCommand().c_str());
		mvwprintw(_win5, index, 28, (std::to_string(it->second->getCpuUsage()).substr(0, 4).c_str()));
		mvwprintw(_win5, index, 36, it->second->getTime().c_str());
		mvwprintw(_win5, index, 48, it->second->getState().c_str());

		long mem = it->second->getMemory();
		std::string memory = "";
		if ( mem > 1000000000 )
			memory = std::to_string(mem / 1000000000) + "G";
		else if ( mem > 1000000 )
			memory = std::to_string(mem / 1000000) + "M";
		else if ( mem > 1000 )
			memory = std::to_string(mem / 1000) + "K";
		else
			memory = std::to_string(mem);

		mvwprintw(_win5, index, 59, (memory.c_str()));
		mvwprintw(_win5, index, 67, (std::to_string(it->second->getCpuMe()).substr(0, 4).c_str()));
		mvwprintw(_win5, index, 73, (std::to_string(it->second->getCpuOthrs()).substr(0, 4).c_str()));
	}
}

void
NCurses::render() {

	if (Monitor::getCurrent()->getModule(0)->isVisible())
	{
		ft_win1();
		box(_win1, ACS_VLINE, ACS_HLINE);
		mvwprintw(_win1, 0, 0, "Identity ");
	}
	else
		wclear(_win1);
	if (Monitor::getCurrent()->getModule(3)->isVisible())
	{
		ft_win2();
		box(_win2, ACS_VLINE, ACS_HLINE);
		mvwprintw(_win2, 0, 0, "Time ");
	}
	else
		wclear(_win2);
	if (Monitor::getCurrent()->getModule(1)->isVisible())
	{
		ft_win3();
		box(_win3, ACS_VLINE, ACS_HLINE);
		mvwprintw(_win3, 0, 0, "Os ");
	}
	else
		wclear(_win3);
	if (Monitor::getCurrent()->getModule(4)->isVisible())
	{
		ft_win4();
		box(_win4, ACS_VLINE, ACS_HLINE);
		mvwprintw(_win4, 0, 0, "Usage ");
	}
	else
		wclear(_win4);
	if (Monitor::getCurrent()->getModule(2)->isVisible())
	{
		ft_win5();
		box(_win5, ACS_VLINE, ACS_HLINE);
		mvwprintw(_win5, 0, 0, "Process ");
	}
	else
		wclear(_win5);

	wrefresh(_win1); 
	wrefresh(_win2); 
	wrefresh(_win3); 
	wrefresh(_win4); 
	wrefresh(_win5); 
}
