#ifndef TIME_HPP
# define TIME_HPP

# include "IMonitorModule.hpp"
# include <string>

class Time: public IMonitorModule {
private:
    std::string         _time;
    std::string         _date;
    bool				_visible;

public:
                        Time();
                        Time(Time const &);
    virtual             ~Time();
    Time                &operator=(Time const &);
    std::string	const   &getDate() const;
    std::string const   &getTime() const;
    virtual bool		isVisible() const;
    virtual void		toggle();
    void		        updateModule();
};

#endif /* TIME_HPP */
