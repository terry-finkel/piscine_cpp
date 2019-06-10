#ifndef NCURSES_HPP
# define NCURSES_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include "Monitor.hpp"
# include <vector>
#include <map>
#include <ncurses.h>
#include "OsInfo.hpp"
#include "OHName.hpp"
#include "ProcessList.hpp"
#include "Time.hpp"
#include "CpuUsage.hpp"
#include "Ram.hpp"

class NCurses : public IMonitorDisplay {
public:
                NCurses();
                NCurses(NCurses const &);
    virtual     ~NCurses();
    NCurses     &operator=(NCurses const &);
    void        render();

    void		ft_win1( void );
	void		ft_win2( void );
	void		ft_win3( void );
	void		ft_win4( void );
	void		ft_win5( void );

    class WinTooSmallException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Your terminal is too small for run our NCurses.");
			}
	};
private:
	WINDOW *_win1;
	WINDOW *_win2;
	WINDOW *_win3;
	WINDOW *_win4;
	WINDOW *_win5;

};

#endif /* NCURSES_HPP */
